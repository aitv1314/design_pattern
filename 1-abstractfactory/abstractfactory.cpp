/*
抽象工厂模式：
    意图 提供一个创建一系列相关或者相互依赖对象的接口，而无需指定他们具体的类
    别名 kit
    适用性
        一个系统要独立于他的产品的创建、组合和表示
        一个系统要有多个产品系列中的一个来配置
        要强调一系列相关的产品对象的设计以便进行联合使用时
        提供一个产品类库，而只想显示他们的接口而不是实现时
    参与者
        AbstactFactory      申明一个创建抽象产品对象的接口
        ConcreteFactory     实现创建具体产品对象的操作
        AbstractProduct     为一类产品对象申明一个接口
        ConcreteProduct     定义一个将被相应的具体工厂创建的产品对象，是想AbstractProduct的接口
        Client              仅由AbstractFactory和AbstractProduct类申明的接口
*/
