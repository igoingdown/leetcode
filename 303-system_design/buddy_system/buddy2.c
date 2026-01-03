#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>

struct buddy2 {
  unsigned size;
  unsigned longest[1]; 
};

#define LEFT_LEAF(index) ((index) * 2 + 1)
#define RIGHT_LEAF(index) ((index) * 2 + 2)
#define PARENT(index) ( ((index) + 1) / 2 - 1)

#define IS_POWER_OF_2(x) (!((x)&((x)-1)))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

#define ALLOC malloc
#define FREE free

static unsigned fixsize(unsigned size) {
  size |= size >> 1;
  size |= size >> 2;
  size |= size >> 4;
  size |= size >> 8;
  size |= size >> 16;
  return size+1;
}


// 以size = 32为例：
// buddy2_new(size = 32)的结果是分配一段内存，
// 内存大小为32 * 2 * 4B, 够存放64个unsigned值，
// 第一个值存size，后面存储longest数组，共63个元素，
// 每个元素代表一棵6层满二叉树的节点，表示这个节点所代表的内存大小，即node_size（0表示被分配出去）。
// 这段内存的映像为：
// 32               32 16 16 8 ... 8(4个8) 4  4 ... 4(8个4) 2  2  ... 2(16个2) 1   1  ... 1(32个1)
// size    longest: 0  1  2  3 ... 6       7  8 ... 14     15 16 ... 30       31 32  ... 62
// 如果这段内存被占用了，该节点存储的值为0.
struct buddy2* buddy2_new( int size ) {
  struct buddy2* self;
  unsigned node_size;
  int i;

  if (size < 1 || !IS_POWER_OF_2(size))
    return NULL;

  self = (struct buddy2*)ALLOC( 2 * size * sizeof(unsigned));
  self->size = size;
  node_size = size * 2;

  for (i = 0; i < 2 * size - 1; ++i) {
    if (IS_POWER_OF_2(i+1))
      // 注意1也是2的整数幂！！！
      node_size /= 2;
    self->longest[i] = node_size;
  }
  return self;
}


void buddy2_destroy( struct buddy2* self) {
  FREE(self);
}


int buddy2_alloc(struct buddy2* self, int size) {
  unsigned index = 0;
  unsigned node_size;
  unsigned offset = 0;

  if (self==NULL)
    return -1;

  if (size <= 0)
    size = 1;
  else if (!IS_POWER_OF_2(size))
    size = fixsize(size);

  if (self->longest[index] < size)
    return -1;

  for(node_size = self->size; node_size != size; node_size /= 2 ) {
    if (self->longest[LEFT_LEAF(index)] >= size)
      index = LEFT_LEAF(index);
    else
      index = RIGHT_LEAF(index);
  }

  self->longest[index] = 0;
  // offset的含义：分配的内存起始位置距离内存块起始点的距离。
  offset = (index + 1) * node_size - self->size;

  // 回溯，将下层被分配出去的空间从父节点中减掉。
  while (index) {
    index = PARENT(index);
    self->longest[index] = 
      MAX(self->longest[LEFT_LEAF(index)], self->longest[RIGHT_LEAF(index)]);
  }

  return offset;
}


void buddy2_free(struct buddy2* self, int offset) {
  unsigned node_size, index = 0;
  unsigned left_longest, right_longest;

  assert(self && offset >= 0 && offset < self->size);

  node_size = 1;
  index = offset + self->size - 1;

  // 从叶子节点上溯，直到找到第一个被占用的块的index，
  // 将块大小还原。
  for (; self->longest[index] ; index = PARENT(index)) {
    node_size *= 2;
    if (index == 0)
      return;
  }
  self->longest[index] = node_size;

  // 继续上溯，把可以聚拢的空闲块聚拢。
  while (index) {
    index = PARENT(index);
    node_size *= 2;

    left_longest = self->longest[LEFT_LEAF(index)];
    right_longest = self->longest[RIGHT_LEAF(index)];
    
    if (left_longest + right_longest == node_size) 
      self->longest[index] = node_size;
    else
      self->longest[index] = MAX(left_longest, right_longest);
  }
}


int buddy2_size(struct buddy2* self, int offset) {
  unsigned node_size, index = 0;

  assert(self && offset >= 0 && offset < self->size);

  node_size = 1;
  for (index = offset + self->size - 1; self->longest[index] ; index = PARENT(index))
    node_size *= 2;

  return node_size;
}


void buddy2_dump(struct buddy2* self) {
  char canvas[65];
  int i,j;
  unsigned node_size, offset;

  if (self == NULL) {
    printf("buddy2_dump: (struct buddy2*)self == NULL");
    return;
  }

  if (self->size > 64) {
    printf("buddy2_dump: (struct buddy2*)self is too big to dump");
    return;
  }

  memset(canvas,'_', sizeof(canvas));
  node_size = self->size * 2;

  for (i = 0; i < 2 * self->size - 1; ++i) {
    if ( IS_POWER_OF_2(i+1) )
      node_size /= 2;

    if ( self->longest[i] == 0 ) {
      if (i >=  self->size - 1) {
        canvas[i - self->size + 1] = '*';
      }
      else if (self->longest[LEFT_LEAF(i)] && self->longest[RIGHT_LEAF(i)]) {
        offset = (i+1) * node_size - self->size;

        for (j = offset; j < offset + node_size; ++j)
          canvas[j] = '*';
      }
    }
  }
  canvas[self->size] = '\0';
  puts(canvas);
}



