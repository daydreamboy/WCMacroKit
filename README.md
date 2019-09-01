# 使用宏手册

[TOC]

## 1、关于`__attribute__`

`__attribute__`用于指示编译器执行某种编译规则，这篇[文章](https://blog.sunnyxx.com/2016/05/14/clang-attributes/)介绍比较清楚。基本格式，如下

```objective-c
__attribute__((XXX))
```



常用attribute，如下

| 名称                                           | 作用               |
| ---------------------------------------------- | ------------------ |
| `__attribute__((objc_subclassing_restricted))` | 限制该类不能被继承 |







## 2、系统常用宏



### （1）NS_DESIGNATED_INITIALIZER

​       `NS_DESIGNATED_INITIALIZER`宏用于标记初始化方法为designated initializer方法。定义和使用designated initializer方法，需要满足下面三个规则[^1]

- 子类的designated initializer方法里，必须调用父类的designated initializer方法来初始化。例如NSObject的designated initializer方法是init方法
- 任何便利初始化方法，都必须最终调用到designated initializer方法
- A class with designated initializers must implement all of the designated initializers of the superclass.（TODO：待理解）

​     简单来说，`NS_DESIGNATED_INITIALIZER`宏用于编译时检查子类是否正确初始化父类，如果存在问题，则给出警告。举个例子，如下

```objective-c
@interface WCThreadSafeArray<__covariant ObjectType> : NSObject
- (instancetype)init;
- (instancetype)initWithCapacity:(NSUInteger)capacity NS_DESIGNATED_INITIALIZER;
@end
  
@implementation WCThreadSafeArray
  
- (instancetype)init { // WARNING: Convenience initializer missing a 'self' call to another initializer
    return [[WCThreadSafeArray alloc] initWithCapacity:0];
}

- (instancetype)initWithCapacity:(NSUInteger)capacity {
    self = [super init];
    if (self) {
      // do some initialization
    }
    return self;
}
@end
```

示例代码，违反上面第二条规则。



## References

[^1]:https://useyourloaf.com/blog/xcode-6-objective-c-modernization/

