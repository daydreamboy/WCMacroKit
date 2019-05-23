//
//  WCMacroSynthesize.h
//  WCMacroKit
//
//  Created by wesley_chen on 2019/5/22.
//

#ifndef WCMacroSynthesize_h
#define WCMacroSynthesize_h

#pragma mark - Synthesize Setters/Getters

// @sa http://stackoverflow.com/questions/11079157/objc-preprocessor-nsstring-macro
// Synthesize Associated Objects
#define SYNTHESIZE_ASSOCIATED_OBJ(getterName, setterName, type)                                                 \
- (void)setterName:(type)object {                                                                               \
    if (object) {                                                                                               \
        objc_setAssociatedObject(self, @selector(getterName), object, OBJC_ASSOCIATION_RETAIN_NONATOMIC);       \
    }                                                                                                           \
}                                                                                                               \
- (type)getterName {                                                                                            \
    return objc_getAssociatedObject(self, @selector(getterName));                                               \
}

// Synthesize Associated Primitives
// @sa https://github.com/itsthejb/ObjcAssociatedObjectHelpers/blob/develop/ObjcAssociatedObjectHelpers/ObjcAssociatedObjectHelpers.h
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

#pragma mark - Synthesize Ivars

#define SYNTHESIZE_IVARS_0()
#define SYNTHESIZE_IVARS_1(p1) \
@synthesize p1=_##p1;
#define SYNTHESIZE_IVARS_2(p1, p2) \
@synthesize p1=_##p1; \
@synthesize p2=_##p2;
#define SYNTHESIZE_IVARS_3(p1, p2, p3) \
@synthesize p1=_##p1; \
@synthesize p2=_##p2; \
@synthesize p3=_##p3;
#define SYNTHESIZE_IVARS_4(p1, p2, p3, p4) \
@synthesize p1=_##p1; \
@synthesize p2=_##p2; \
@synthesize p3=_##p3; \
@synthesize p4=_##p4;
#define SYNTHESIZE_IVARS_5(p1, p2, p3, p4, p5) \
@synthesize p1=_##p1; \
@synthesize p2=_##p2; \
@synthesize p3=_##p3; \
@synthesize p4=_##p4; \
@synthesize p5=_##p5;
#define SYNTHESIZE_IVARS_6(p1, p2, p3, p4, p5, p6) \
@synthesize p1=_##p1; \
@synthesize p2=_##p2; \
@synthesize p3=_##p3; \
@synthesize p4=_##p4; \
@synthesize p5=_##p5; \
@synthesize p6=_##p6;
#define SYNTHESIZE_IVARS_7(p1, p2, p3, p4, p5, p6, p7) \
@synthesize p1=_##p1; \
@synthesize p2=_##p2; \
@synthesize p3=_##p3; \
@synthesize p4=_##p4; \
@synthesize p5=_##p5; \
@synthesize p6=_##p6; \
@synthesize p7=_##p7;
#define SYNTHESIZE_IVARS_8(p1, p2, p3, p4, p5, p6, p7, p8) \
@synthesize p1=_##p1; \
@synthesize p2=_##p2; \
@synthesize p3=_##p3; \
@synthesize p4=_##p4; \
@synthesize p5=_##p5; \
@synthesize p6=_##p6; \
@synthesize p7=_##p7; \
@synthesize p8=_##p8;
#define SYNTHESIZE_IVARS_9(p1, p2, p3, p4, p5, p6, p7, p8, p9) \
@synthesize p1=_##p1; \
@synthesize p2=_##p2; \
@synthesize p3=_##p3; \
@synthesize p4=_##p4; \
@synthesize p5=_##p5; \
@synthesize p6=_##p6; \
@synthesize p7=_##p7; \
@synthesize p8=_##p8; \
@synthesize p9=_##p9;
#define SYNTHESIZE_IVARS_10(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10) \
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
#define SYNTHESIZE_IVARS_11(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11) \
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
#define SYNTHESIZE_IVARS_12(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12) \
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
#define SYNTHESIZE_IVARS_13(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13) \
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
#define SYNTHESIZE_IVARS_14(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14) \
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
#define SYNTHESIZE_IVARS_15(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15) \
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
#define SYNTHESIZE_IVARS_16(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, p16) \
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
#define SYNTHESIZE_IVARS_17(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, p16, p17) \
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
#define SYNTHESIZE_IVARS_18(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, p16, p17, p18) \
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
#define SYNTHESIZE_IVARS_19(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, p16, p17, p18, p19) \
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
#define SYNTHESIZE_IVARS_20(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, p16, p17, p18, p19, p20) \
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
#define SYNTHESIZE_IVARS_SHIFT(x,p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11,p12,p13,p14,p15,p16,p17,p18,p19,p20,FUNC, ...) FUNC

// CONFIGURE: add p21 before SYNTHESIZE_IVARS_20

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
 
 SYNTHESIZE_IVARS(property1, property2);
 SYNTHESIZE_IVARS(property1, property2, ..., propertyN);
 
 @end
 
 @endcode
 */
#define SYNTHESIZE_IVARS(...) SYNTHESIZE_IVARS_SHIFT(,##__VA_ARGS__,\
SYNTHESIZE_IVARS_20(__VA_ARGS__),\
SYNTHESIZE_IVARS_19(__VA_ARGS__),\
SYNTHESIZE_IVARS_18(__VA_ARGS__),\
SYNTHESIZE_IVARS_17(__VA_ARGS__),\
SYNTHESIZE_IVARS_16(__VA_ARGS__),\
SYNTHESIZE_IVARS_15(__VA_ARGS__),\
SYNTHESIZE_IVARS_14(__VA_ARGS__),\
SYNTHESIZE_IVARS_13(__VA_ARGS__),\
SYNTHESIZE_IVARS_12(__VA_ARGS__),\
SYNTHESIZE_IVARS_11(__VA_ARGS__),\
SYNTHESIZE_IVARS_10(__VA_ARGS__),\
SYNTHESIZE_IVARS_9(__VA_ARGS__),\
SYNTHESIZE_IVARS_8(__VA_ARGS__),\
SYNTHESIZE_IVARS_7(__VA_ARGS__),\
SYNTHESIZE_IVARS_6(__VA_ARGS__),\
SYNTHESIZE_IVARS_5(__VA_ARGS__),\
SYNTHESIZE_IVARS_4(__VA_ARGS__),\
SYNTHESIZE_IVARS_3(__VA_ARGS__),\
SYNTHESIZE_IVARS_2(__VA_ARGS__),\
SYNTHESIZE_IVARS_1(__VA_ARGS__),\
SYNTHESIZE_IVARS_0(__VA_ARGS__)\
)

#endif /* WCMacroSynthesize_h */
