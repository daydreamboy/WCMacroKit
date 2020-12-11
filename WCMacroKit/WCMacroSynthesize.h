//
//  WCMacroSynthesize.h
//  WCMacroKit
//
//  Created by wesley_chen on 2019/5/22.
//

#ifndef WCMacroSynthesize_h
#define WCMacroSynthesize_h

#pragma mark - Synthesize Setters/Getters

#pragma mark > Associated Objects

/**
 Synthesize Associated Objects

 @param getterName the getter method name
 @param setterName the setter method name without colon
 @param type the object type
 @see http://stackoverflow.com/questions/11079157/objc-preprocessor-nsstring-macro
 @header #import <objc/runtime.h>
 @code
 
 SYNTHESIZE_ASSOCIATED_OBJECT(associatedString, setAssociatedString, NSString *);
 SYNTHESIZE_ASSOCIATED_OBJECT(associatedBlock, setAssociatedBlock, WCNavigatorCompletionBlock);

 @endcode
 */
#define SYNTHESIZE_ASSOCIATED_OBJECT(getterName, setterName, type)                                              \
- (void)setterName:(type)object {                                                                               \
    if (object) {                                                                                               \
        objc_setAssociatedObject(self, @selector(getterName), object, OBJC_ASSOCIATION_RETAIN_NONATOMIC);       \
    }                                                                                                           \
}                                                                                                               \
- (type)getterName {                                                                                            \
    return objc_getAssociatedObject(self, @selector(getterName));                                               \
}

/**
 Synthesize Associated Primitives

 @param getterName the getter method name
 @param setterName the setter method name without colon
 @param type the object type
 @see https://github.com/itsthejb/ObjcAssociatedObjectHelpers/blob/develop/ObjcAssociatedObjectHelpers/ObjcAssociatedObjectHelpers.h
 @header #import <objc/runtime.h>
 @code
 
 SYNTHESIZE_ASSOCIATED_PRIMITIVE(cgFloatNum, setCgFloatNum, CGFloat);
 SYNTHESIZE_ASSOCIATED_PRIMITIVE(intNum, setIntNum, int);

 @endcode
 */
#define SYNTHESIZE_ASSOCIATED_PRIMITIVE(getterName, setterName, type)                                           \
- (void)setterName:(type)value {                                                                                \
    NSValue *nsValue = [NSValue value:&value withObjCType:@encode(type)];                                       \
    objc_setAssociatedObject(self, @selector(getterName), nsValue, OBJC_ASSOCIATION_RETAIN_NONATOMIC);          \
}                                                                                                               \
- (type)getterName {                                                                                            \
    type value;                                                                                                 \
    memset(&value, 0, sizeof(type));                                                                            \
    NSValue *nsValue = objc_getAssociatedObject(self, @selector(getterName));                                   \
    [nsValue getValue:&value];                                                                                  \
    return value;                                                                                               \
}

#pragma mark > Class Property

/**
 Synthesize class property primitives

 @param getterName the getter method name
 @param setterName the setter method name without colon
 @param type the primitive type
 @see https://useyourloaf.com/blog/objective-c-class-properties/
 @code
 
 SYNTHESIZE_CLASS_PROPERTY_PRIMITIVE(cgFloatNum, setCgFloatNum, CGFloat);
 SYNTHESIZE_CLASS_PROPERTY_PRIMITIVE(intNum, setIntNum, int);

 @endcode
 */
#define SYNTHESIZE_CLASS_PROPERTY_PRIMITIVE(getterName, setterName, type)                                       \
static type s_##getterName;                                                                                     \
+ (void)setterName:(type)value {                                                                                \
    s_##getterName = value;                                                                                     \
}                                                                                                               \
+ (type)getterName {                                                                                            \
    return s_##getterName;                                                                                      \
}

#define SYNTHESIZE_CLASS_PROPERTY_OBJECT(getterName, setterName, type)                                          \
static type s_##getterName;                                                                                     \
+ (void)setterName:(type)value {                                                                                \
    s_##getterName = value;                                                                                     \
}                                                                                                               \
+ (type)getterName {                                                                                            \
    return s_##getterName;                                                                                      \
}

#pragma mark - Synthesize Ivars

#define SYNTHESIZE_PROPERTYS_0()
#define SYNTHESIZE_PROPERTYS_1(p1) \
@synthesize p1=_##p1;
#define SYNTHESIZE_PROPERTYS_2(p1, p2) \
@synthesize p1=_##p1; \
@synthesize p2=_##p2;
#define SYNTHESIZE_PROPERTYS_3(p1, p2, p3) \
@synthesize p1=_##p1; \
@synthesize p2=_##p2; \
@synthesize p3=_##p3;
#define SYNTHESIZE_PROPERTYS_4(p1, p2, p3, p4) \
@synthesize p1=_##p1; \
@synthesize p2=_##p2; \
@synthesize p3=_##p3; \
@synthesize p4=_##p4;
#define SYNTHESIZE_PROPERTYS_5(p1, p2, p3, p4, p5) \
@synthesize p1=_##p1; \
@synthesize p2=_##p2; \
@synthesize p3=_##p3; \
@synthesize p4=_##p4; \
@synthesize p5=_##p5;
#define SYNTHESIZE_PROPERTYS_6(p1, p2, p3, p4, p5, p6) \
@synthesize p1=_##p1; \
@synthesize p2=_##p2; \
@synthesize p3=_##p3; \
@synthesize p4=_##p4; \
@synthesize p5=_##p5; \
@synthesize p6=_##p6;
#define SYNTHESIZE_PROPERTYS_7(p1, p2, p3, p4, p5, p6, p7) \
@synthesize p1=_##p1; \
@synthesize p2=_##p2; \
@synthesize p3=_##p3; \
@synthesize p4=_##p4; \
@synthesize p5=_##p5; \
@synthesize p6=_##p6; \
@synthesize p7=_##p7;
#define SYNTHESIZE_PROPERTYS_8(p1, p2, p3, p4, p5, p6, p7, p8) \
@synthesize p1=_##p1; \
@synthesize p2=_##p2; \
@synthesize p3=_##p3; \
@synthesize p4=_##p4; \
@synthesize p5=_##p5; \
@synthesize p6=_##p6; \
@synthesize p7=_##p7; \
@synthesize p8=_##p8;
#define SYNTHESIZE_PROPERTYS_9(p1, p2, p3, p4, p5, p6, p7, p8, p9) \
@synthesize p1=_##p1; \
@synthesize p2=_##p2; \
@synthesize p3=_##p3; \
@synthesize p4=_##p4; \
@synthesize p5=_##p5; \
@synthesize p6=_##p6; \
@synthesize p7=_##p7; \
@synthesize p8=_##p8; \
@synthesize p9=_##p9;
#define SYNTHESIZE_PROPERTYS_10(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10) \
@synthesize p1=_##p1; \
@synthesize p2=_##p2; \
@synthesize p3=_##p3; \
@synthesize p4=_##p4; \
@synthesize p5=_##p5; \
@synthesize p6=_##p6; \
@synthesize p7=_##p7; \
@synthesize p8=_##p8; \
@synthesize p9=_##p9; \
@synthesize p10=_##p10;
#define SYNTHESIZE_PROPERTYS_11(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11) \
@synthesize p1=_##p1; \
@synthesize p2=_##p2; \
@synthesize p3=_##p3; \
@synthesize p4=_##p4; \
@synthesize p5=_##p5; \
@synthesize p6=_##p6; \
@synthesize p7=_##p7; \
@synthesize p8=_##p8; \
@synthesize p9=_##p9; \
@synthesize p10=_##p10; \
@synthesize p11=_##p11;
#define SYNTHESIZE_PROPERTYS_12(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12) \
@synthesize p1=_##p1; \
@synthesize p2=_##p2; \
@synthesize p3=_##p3; \
@synthesize p4=_##p4; \
@synthesize p5=_##p5; \
@synthesize p6=_##p6; \
@synthesize p7=_##p7; \
@synthesize p8=_##p8; \
@synthesize p9=_##p9; \
@synthesize p10=_##p10; \
@synthesize p11=_##p11; \
@synthesize p12=_##p12;
#define SYNTHESIZE_PROPERTYS_13(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13) \
@synthesize p1=_##p1; \
@synthesize p2=_##p2; \
@synthesize p3=_##p3; \
@synthesize p4=_##p4; \
@synthesize p5=_##p5; \
@synthesize p6=_##p6; \
@synthesize p7=_##p7; \
@synthesize p8=_##p8; \
@synthesize p9=_##p9; \
@synthesize p10=_##p10; \
@synthesize p11=_##p11; \
@synthesize p12=_##p12;\
@synthesize p13=_##p13;
#define SYNTHESIZE_PROPERTYS_14(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14) \
@synthesize p1=_##p1; \
@synthesize p2=_##p2; \
@synthesize p3=_##p3; \
@synthesize p4=_##p4; \
@synthesize p5=_##p5; \
@synthesize p6=_##p6; \
@synthesize p7=_##p7; \
@synthesize p8=_##p8; \
@synthesize p9=_##p9; \
@synthesize p10=_##p10; \
@synthesize p11=_##p11; \
@synthesize p12=_##p12;\
@synthesize p13=_##p13; \
@synthesize p14=_##p14;
#define SYNTHESIZE_PROPERTYS_15(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15) \
@synthesize p1=_##p1; \
@synthesize p2=_##p2; \
@synthesize p3=_##p3; \
@synthesize p4=_##p4; \
@synthesize p5=_##p5; \
@synthesize p6=_##p6; \
@synthesize p7=_##p7; \
@synthesize p8=_##p8; \
@synthesize p9=_##p9; \
@synthesize p10=_##p10; \
@synthesize p11=_##p11; \
@synthesize p12=_##p12;\
@synthesize p13=_##p13; \
@synthesize p14=_##p14; \
@synthesize p15=_##p15;
#define SYNTHESIZE_PROPERTYS_16(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, p16) \
@synthesize p1=_##p1; \
@synthesize p2=_##p2; \
@synthesize p3=_##p3; \
@synthesize p4=_##p4; \
@synthesize p5=_##p5; \
@synthesize p6=_##p6; \
@synthesize p7=_##p7; \
@synthesize p8=_##p8; \
@synthesize p9=_##p9; \
@synthesize p10=_##p10; \
@synthesize p11=_##p11; \
@synthesize p12=_##p12;\
@synthesize p13=_##p13; \
@synthesize p14=_##p14; \
@synthesize p15=_##p15; \
@synthesize p16=_##p16;
#define SYNTHESIZE_PROPERTYS_17(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, p16, p17) \
@synthesize p1=_##p1; \
@synthesize p2=_##p2; \
@synthesize p3=_##p3; \
@synthesize p4=_##p4; \
@synthesize p5=_##p5; \
@synthesize p6=_##p6; \
@synthesize p7=_##p7; \
@synthesize p8=_##p8; \
@synthesize p9=_##p9; \
@synthesize p10=_##p10; \
@synthesize p11=_##p11; \
@synthesize p12=_##p12;\
@synthesize p13=_##p13; \
@synthesize p14=_##p14; \
@synthesize p15=_##p15; \
@synthesize p16=_##p16; \
@synthesize p17=_##p17;
#define SYNTHESIZE_PROPERTYS_18(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, p16, p17, p18) \
@synthesize p1=_##p1; \
@synthesize p2=_##p2; \
@synthesize p3=_##p3; \
@synthesize p4=_##p4; \
@synthesize p5=_##p5; \
@synthesize p6=_##p6; \
@synthesize p7=_##p7; \
@synthesize p8=_##p8; \
@synthesize p9=_##p9; \
@synthesize p10=_##p10; \
@synthesize p11=_##p11; \
@synthesize p12=_##p12;\
@synthesize p13=_##p13; \
@synthesize p14=_##p14; \
@synthesize p15=_##p15; \
@synthesize p16=_##p16; \
@synthesize p17=_##p17; \
@synthesize p18=_##p18;
#define SYNTHESIZE_PROPERTYS_19(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, p16, p17, p18, p19) \
@synthesize p1=_##p1; \
@synthesize p2=_##p2; \
@synthesize p3=_##p3; \
@synthesize p4=_##p4; \
@synthesize p5=_##p5; \
@synthesize p6=_##p6; \
@synthesize p7=_##p7; \
@synthesize p8=_##p8; \
@synthesize p9=_##p9; \
@synthesize p10=_##p10; \
@synthesize p11=_##p11; \
@synthesize p12=_##p12;\
@synthesize p13=_##p13; \
@synthesize p14=_##p14; \
@synthesize p15=_##p15; \
@synthesize p16=_##p16; \
@synthesize p17=_##p17; \
@synthesize p18=_##p18; \
@synthesize p19=_##p19;
#define SYNTHESIZE_PROPERTYS_20(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, p16, p17, p18, p19, p20) \
@synthesize p1=_##p1; \
@synthesize p2=_##p2; \
@synthesize p3=_##p3; \
@synthesize p4=_##p4; \
@synthesize p5=_##p5; \
@synthesize p6=_##p6; \
@synthesize p7=_##p7; \
@synthesize p8=_##p8; \
@synthesize p9=_##p9; \
@synthesize p10=_##p10; \
@synthesize p11=_##p11; \
@synthesize p12=_##p12;\
@synthesize p13=_##p13; \
@synthesize p14=_##p14; \
@synthesize p15=_##p15; \
@synthesize p16=_##p16; \
@synthesize p17=_##p17; \
@synthesize p18=_##p18; \
@synthesize p19=_##p19; \
@synthesize p20=_##p20;
// CONFIGURE: add more @synthesize...@synthesize p21=_##p21;

// CONFIGURE: add p21 before FUNC
#define SYNTHESIZE_PROPERTYS_SHIFT(x,p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11,p12,p13,p14,p15,p16,p17,p18,p19,p20,FUNC, ...) FUNC

// CONFIGURE: add p21 before SYNTHESIZE_PROPERTYS_20

/**
 Synthesize ivars

 @param ... the property list
 @see https://stackoverflow.com/a/8814003
 @code
 
 @protocol SomeProtocol <NSObject>
 @property property1;
 ...
 @property propertyN;
 @end
 
 @interface SomeClass () <SomeProtocol>
 @end
 
 @implementation SomeClass
 
 SYNTHESIZE_PROPERTYS(property1, property2);
 SYNTHESIZE_PROPERTYS(property1, property2, ..., propertyN);
 
 @end
 
 @endcode
 */
#define SYNTHESIZE_PROPERTYS(...) SYNTHESIZE_PROPERTYS_SHIFT(,##__VA_ARGS__,\
SYNTHESIZE_PROPERTYS_20(__VA_ARGS__),\
SYNTHESIZE_PROPERTYS_19(__VA_ARGS__),\
SYNTHESIZE_PROPERTYS_18(__VA_ARGS__),\
SYNTHESIZE_PROPERTYS_17(__VA_ARGS__),\
SYNTHESIZE_PROPERTYS_16(__VA_ARGS__),\
SYNTHESIZE_PROPERTYS_15(__VA_ARGS__),\
SYNTHESIZE_PROPERTYS_14(__VA_ARGS__),\
SYNTHESIZE_PROPERTYS_13(__VA_ARGS__),\
SYNTHESIZE_PROPERTYS_12(__VA_ARGS__),\
SYNTHESIZE_PROPERTYS_11(__VA_ARGS__),\
SYNTHESIZE_PROPERTYS_10(__VA_ARGS__),\
SYNTHESIZE_PROPERTYS_9(__VA_ARGS__),\
SYNTHESIZE_PROPERTYS_8(__VA_ARGS__),\
SYNTHESIZE_PROPERTYS_7(__VA_ARGS__),\
SYNTHESIZE_PROPERTYS_6(__VA_ARGS__),\
SYNTHESIZE_PROPERTYS_5(__VA_ARGS__),\
SYNTHESIZE_PROPERTYS_4(__VA_ARGS__),\
SYNTHESIZE_PROPERTYS_3(__VA_ARGS__),\
SYNTHESIZE_PROPERTYS_2(__VA_ARGS__),\
SYNTHESIZE_PROPERTYS_1(__VA_ARGS__),\
SYNTHESIZE_PROPERTYS_0(__VA_ARGS__)\
)

#define SYNTHESIZE_PROPERTY(property) \
@synthesize property = _##property;

#endif /* WCMacroSynthesize_h */
