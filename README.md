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



| 宏                | 作用                              |
| ----------------- | --------------------------------- |
|                   |                                   |
| NS_REQUIRES_SUPER | 标记某个方法需要调用super方法[^4] |





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



### （2）NSAssert



### （3）__IPHONE_OS_VERSION_MIN_REQUIRED

`__IPHONE_OS_VERSION_MIN_REQUIRED`宏对应iOS Deployment Target的版本号。

举个例子，如果iOS Deployment Target设置8.0，则在满足该版本及以上才编译某些代码，可以使用下面方式

```objective-c
#if __IPHONE_OS_VERSION_MIN_REQUIRED >= 80000
...
#endif
```



### （4）__IPHONE_XX_Y

​        `__IPHONE_XX_Y`定义在Availability.h中，主版本号不同的iOS系统版本，该文件定义的宏不同，例如在iOS 11 SDK中定义了`__IPHONE_11_0`等，而iOS 10 SDK没有定义该宏。如果代码需要向下编译兼容，则需要使用`__IPHONE_11_0`。

​        为什么代码需要向下编译兼容，例如UIScrollView的adjustedContentInset属性在iOS 11才有，而在老的Xcode版本中支持不了iOS 11，但是又需要编译代码（一般是测代码在低版本模拟器上）。这时iOS SDK中UIScrollView没有adjustedContentInset属性，则编译报错。为了解决这类问题，采用`__IPHONE_XX_Y`做条件编译，如下

```objective-c
#ifdef __IPHONE_11_0
<Code use UIScrollView @adjustedContentInset>
#else
<Code should not use UIScrollView @adjustedContentInset>
#endif
```

注意

> 宏只是让代码编译通过，还需要运行时判断该API是否可否，否则高版本API在低版本iOS上运行会报找不到方法的异常





## 3、不常用宏

编译器提供的宏

| 宏                        | 作用                                                       | 说明 |
| ------------------------- | ---------------------------------------------------------- | ---- |
| `__TIME__`                | 当前文件被编译的时间，例如"16:55:29"                       |      |
| `__TIMESTAMP__`           | 当前文件被编译的时间和日期，例如"Sat May 30 16:55:10 2020" |      |
| `__COUNTER__`             | 在当前文件中，`__COUNTER__`宏被按照编译顺序替换为0、1、2等 |      |
| `__BASE_FILE__`           | 当前文件的绝对路径                                         |      |
| `__FILE_NAME__`[^2]       | 当前文件的文件名包括后缀                                   |      |
| `__PRETTY_FUNCTION__`[^3] | 当前方法                                                   |      |



系统提供的宏

| 宏                | 作用 | 说明 |
| ----------------- | ---- | ---- |
| CGFLOAT_IS_DOUBLE |      |      |





## 4、宏的identifier

宏的identifier可以有特殊字符前缀，`$`、`_`等





// TODO

https://stackoverflow.com/questions/17281901/ignoring-an-undefined-symbol-in-a-dynamic-library-from-xcode



## References

[^1]:https://useyourloaf.com/blog/xcode-6-objective-c-modernization/

[^2]:https://reviews.llvm.org/D17741

[^3]:https://roadfiresoftware.com/2013/12/logging-class-and-method-names-in-objective-c/

[^4]:https://stackoverflow.com/a/22945846



