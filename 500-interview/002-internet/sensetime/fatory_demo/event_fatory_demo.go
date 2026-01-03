package main

import "fmt"

type EventConsumer interface {
	Consume(msg string) // 事件消费方法
}

type orderProcessor struct {
}

// Consume 实现 EventConsumer 接口的 Consume 方法
func (c *orderProcessor) Consume(msg string) {
	fmt.Printf("处理订单事件：%s\n", msg)
}

type freightProcessor struct {
}

// Consume 实现 EventConsumer 接口的 Consume 方法
func (f *freightProcessor) Consume(msg string) {
	fmt.Printf("处理运费事件：%s\n", msg)
}

// NewEventConsumer 命名规范：New + 接口名（NewEventConsumer），返回接口类型
func NewEventConsumer(consumerType string) (EventConsumer, error) {
	switch consumerType {
	case "order":
		return &orderProcessor{}, nil
	case "freight":
		return &freightProcessor{}, nil
	default:
		return nil, fmt.Errorf("不支持的事件消费者类型：%s", consumerType)
	}
}

// 调用示例
func main() {

	// 调用方只依赖 EventConsumer 接口，不关心具体实现
	orderConsumer, _ := NewEventConsumer("order")
	orderConsumer.Consume("订单创建事件")

	freightConsumer, _ := NewEventConsumer("freight")
	freightConsumer.Consume("运费计算事件")
}
