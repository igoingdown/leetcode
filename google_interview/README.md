---

tags:
  - c++
  - Google
  - algorithm
  - 算法
  - interview
  - 面试
---


# 谷歌一面

1. 电话从加州打过来，我心一凉！
2. 做题
	* 两棵树A和B，定义一种操作，将一个节点的左子和右子互换。判断A经过多次操作后能否变换为B。
		* 递归，首先AB的根节点相同；然后A的左子树能转成B的右子树同时A的右子树能转成B的右子树，或者A的左子树可以转成B的右子树且A的右子树可以转成B的左子树
		 * 将A和B按照相同的规则转为具有一定规则的树，然后看两个树是否相同。