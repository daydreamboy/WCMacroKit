# 使用宏手册

[TOC]

## 1、关于宏

宏在预处理器阶段中做展开，进行代码替换。

### (1) 宏的来源

宏有下面几个来源

* 编译器(GCC、Clang等)内置的宏，例如`__GNUC__`
* 用户指定编译选项定义的宏，例如Xcode中在Debug scheme下面，默认配置了DEBUG宏
* 语言标准定义的宏，例如C99、C++11定义一些标准的宏
* 系统库定义的宏
* 用户代码定义的宏



### (2) 宏的作用

宏有下面几个作用

* 简化代码
* 编写适配多个编译平台的代码



### (3) 宏的identifier

宏的identifier可以有特殊字符前缀，`$`、`_`等





## 2、iOS系统常用宏



| 宏                | 作用                              |
| ----------------- | --------------------------------- |
|                   |                                   |
| NS_REQUIRES_SUPER | 标记某个方法需要调用super方法[^4] |



系统提供的宏

| 宏                | 作用 | 说明 |
| ----------------- | ---- | ---- |
| CGFLOAT_IS_DOUBLE |      |      |





### (1) NS_DESIGNATED_INITIALIZER

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



### (2) NSAssert



### (3) __IPHONE_OS_VERSION_MIN_REQUIRED

`__IPHONE_OS_VERSION_MIN_REQUIRED`宏对应iOS Deployment Target的版本号。

举个例子，如果iOS Deployment Target设置8.0，则在满足该版本及以上才编译某些代码，可以使用下面方式

```objective-c
#if __IPHONE_OS_VERSION_MIN_REQUIRED >= 80000
...
#endif
```



### (4) __IPHONE_XX_Y

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







## 3、常用宏

### (1) C标准定义的宏

C标准定义了下面一些宏[^6]，如下

| 宏         | 作用                                    | 说明 |
| ---------- | --------------------------------------- | ---- |
| `__FILE__` |                                         |      |
| `__LINE__` |                                         |      |
| `__DATE__` | 当前文件被编译的日期，例如"May 26 2022" |      |
| `__TIME__` | 当前文件被编译的时间，例如"16:55:29"    |      |



### (2) C语言预定义的变量

#### a. `__func__`

`__func__`是C99定义的静态变量，表示当前函数名。它不是一个宏，但可以当成宏使用。

官方文档描述[^5]，如下

> Within every *function-body*, the special predefined variable __func__ with block scope and static storage duration is available, as if defined immediately after the opening brace by
>
> ```
> static const char __func__[] = "function name";
> ```
>
> This special identifier is sometimes used in combination with the [predefined macro constants](dfile:///Users/wesley_chen/Library/Application Support/Dash/DocSets/C/C.docset/Contents/Resources/Documents/en.cppreference.com/w/c/preprocessor/replace.html) __FILE__ and __LINE__, for example, by [assert](dfile:///Users/wesley_chen/Library/Application Support/Dash/DocSets/C/C.docset/Contents/Resources/Documents/en.cppreference.com/w/c/error/assert.html).



### (3) C++标准定义的宏

C++标准定义了下面一些宏[^7]，如下

| 宏            | 作用                                    | 说明 |
| ------------- | --------------------------------------- | ---- |
| `__cplusplus` |                                         |      |
| `__FILE__`    |                                         |      |
| `__LINE__`    |                                         |      |
| `__DATE__`    | 当前文件被编译的日期，例如"May 26 2022" |      |
| `__TIME__`    | 当前文件被编译的时间，例如"16:55:29"    |      |



### (4) GCC编译器的预定义宏

GCC编译器的预定义宏，可以参考这篇官方文档[^8]可以分为4类，如下

* [Standard Predefined Macros](https://gcc.gnu.org/onlinedocs/cpp/Standard-Predefined-Macros.html#Standard-Predefined-Macros)
* [Common Predefined Macros](https://gcc.gnu.org/onlinedocs/cpp/Common-Predefined-Macros.html#Common-Predefined-Macros)
* [System-specific Predefined Macros](https://gcc.gnu.org/onlinedocs/cpp/System-specific-Predefined-Macros.html#System-specific-Predefined-Macros)
* [C++ Named Operators](https://gcc.gnu.org/onlinedocs/cpp/C_002b_002b-Named-Operators.html#C_002b_002b-Named-Operators)



说明

> 可以使用下面命令来输出GCC支持的预定义宏[^10]，如下
>
> ```shell
> $ gcc -x c /dev/null -dM -E
> ```
>
> 



#### a. Standard Predefined Macros

这里列举一些常用的宏[^11]，如下

| 宏            | 作用 | 说明 |
| ------------- | ---- | ---- |
| `__FILE__`    |      |      |
| `__LINE__`    |      |      |
| `__DATE__`    |      |      |
| `__TIME__`    |      |      |
| `__cplusplus` |      |      |
| `__OBJC__`    |      |      |



#### b. Common Predefined Macros

这里列举一些常用的宏[^12]，如下

| 宏            | 作用                                                       | 说明 |
| ------------- | ---------------------------------------------------------- | ---- |
| `__COUNTER__` | 在当前文件中，`__COUNTER__`宏被按照编译顺序替换为0、1、2等 |      |
| `__GNUC__`    |                                                            |      |





### (5) GCC预定义的变量

#### a. `__PRETTY_FUNCTION__`[^3]

官方文档描述[^13]，如下

> In C, `__PRETTY_FUNCTION__` is yet another name for `__func__`, except that at file scope (or, in C++, namespace scope), it evaluates to the string `"top level"`. In addition, in C++, `__PRETTY_FUNCTION__` contains the signature of the function as well as its bare name. 



举个例子，如下

```c
extern "C" int printf (const char *, ...);

class a {
 public:
  void sub (int i)
    {
      printf ("__FUNCTION__ = %s\n", __FUNCTION__);
      printf ("__PRETTY_FUNCTION__ = %s\n", __PRETTY_FUNCTION__);
    }
};

int
main (void)
{
  a ax;
  ax.sub (0);
  return 0;
}
```



#### b. `__FUNCTION__`

官方文档描述[^13]，如下

> `__FUNCTION__` is another name for `__func__`, provided for backward compatibility with old versions of GCC.
>
> The identifier `__func__` is implicitly declared by the translator as if, immediately following the opening brace of each function definition, the declaration
>
> ```
> static const char __func__[] = "function-name";
> ```



### (6) Clang编译器的预定义宏

Clang编译器的预定义宏，可以参考这篇官方文档[^9]

这里列举一些常用的宏，如下

| 宏                  | 作用                                                       | 说明 |
| ------------------- | ---------------------------------------------------------- | ---- |
| `__BASE_FILE__`     | 当前文件的绝对路径                                         |      |
| `__FILE_NAME__`     | 当前文件的文件名包括后缀[^2]                               |      |
| `__TIMESTAMP__`     | 当前文件被编译的时间和日期，例如"Sat May 30 16:55:10 2020" |      |
| `__clang__`         |                                                            |      |
| `__clang_version__` |                                                            |      |



可以使用下面的命令来输出Clang支持的预定义宏[^10]，如下

```shell
$ xcrun clang -x c /dev/null -dM -E
```



#### a. 标记宏为Deprecated

使用`#pragma clang deprecated`可以标记宏为Deprecated，在使用处会产生一个警告。

举个例子[^9]，如下

```objective-c
#define MY_MIN(x, y) x < y ? x : y
#pragma clang deprecated(MY_MIN, "use std::min instead")

- (void)test_clang_deprecated {
    int min = MY_MIN(1, 2); // Warning: Macro 'MY_MIN' has been marked as deprecated: use std::min instead
    NSLog(@"min:%d", min);
}
```





## 4、Clang Module导致头文件条件编译无效的问题

当编译的target开启Clang Module（CLANG_ENABLE_MODULES=YES），可能会导致依赖库的头文件中条件编译无效。

举个例子，如下

zzz.m

```objective-c
#define InternalToggle 1
#import <SomeFramework/xxx.h>

void test()
{
  ConditionalMacroWillUseInternalToggle(@"arg1");
}
```



xxx.h

```objective-c
#ifdef InternalToggle
#define ConditionalMacroWillUseInternalToggle doSomething1
#else
#define ConditionalMacroWillUseInternalToggle doSomething2
#endif
```

如果开启Clang Module，上面的头文件，会提前编译，而不是导入代码在zzz.m再编译，因此在`#import <SomeFramework/xxx.h>`之前定义的宏InternalToggle，没有起到作用。xxx.h中的条件编译，总是走到else分支。

如果关闭Clang Module，上面的头文件，导入代码在zzz.m再编译，因此是预期的条件编译，xxx.h中的条件编译，总是走到if分支。



解决方案：

* 关闭Clang Module，这个方法不是最好的，而且关闭后会影响编译性能

* 采用重定义宏的方式来做“条件”切换。举个例子，如下

  ```objective-c
  // .h
  #define WCLog(fmt, ...) { NSLog((fmt), ## __VA_ARGS__); }
  #define WCLogPrefix(fmt, ...) { NSLog((WCLogModule fmt), ## __VA_ARGS__); }
  
  // .m
  #import <WCMacroKit/WCMacroKit.h>
  
  #define WCLogModule @"[Test_MacroLog] "
  #undef WCLog
  #define WCLog WCLogPrefix
  
  - (void)test_WCLog {
      NSString *message = @"message"      @", a.k.a msg";
      WCLog(@"log: %@", message);
      WCLog(@"This is a log");
  }
  ```

  如果用到WCLog宏的源文件很多，可以做一个wrapper header文件，将上面重定义宏的代码，放到这个wrapper heade。例如

  ```objective-c
  // wrapper.h
  #import <WCMacroKit/WCMacroKit.h>
  
  #define WCLogModule @"[TestTarget] "
  #undef WCLog
  #define WCLog WCLogPrefix
  
  // .m
  #import "wrapper.h"
  - (void)test_WCLog {
      NSString *message = @"message"      @", a.k.a msg";
      WCLog(@"log: %@", message);
      WCLog(@"This is a log");
  }
  ```

  











## References

[^1]:https://useyourloaf.com/blog/xcode-6-objective-c-modernization/

[^2]:https://reviews.llvm.org/D17741

[^3]:https://roadfiresoftware.com/2013/12/logging-class-and-method-names-in-objective-c/

[^4]:https://stackoverflow.com/a/22945846

[^5]:https://en.cppreference.com/w/c/language/function_definition#func
[^6]:https://en.cppreference.com/w/c/preprocessor/replace
[^7]:https://en.cppreference.com/w/cpp/preprocessor/replace
[^8]:https://gcc.gnu.org/onlinedocs/cpp/Predefined-Macros.html
[^9]:https://clang.llvm.org/docs/LanguageExtensions.html#builtin-macros
[^10]:https://blog.kowalczyk.info/article/j/guide-to-predefined-macros-in-c-compilers-gcc-clang-msvc-etc..html

[^11]:https://gcc.gnu.org/onlinedocs/cpp/Standard-Predefined-Macros.html#Standard-Predefined-Macros
[^12]:https://gcc.gnu.org/onlinedocs/cpp/Common-Predefined-Macros.html#Common-Predefined-Macros
[^13]:https://gcc.gnu.org/onlinedocs/gcc/Function-Names.html

