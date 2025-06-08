//
//  WCMacroString.h
//  WCMacroKit
//
//  Created by wesley_chen on 2019/3/9.
//

#ifndef WCMacroString_h
#define WCMacroString_h

// String
#pragma mark - String

#pragma mark > String conversion

// BOOL to string
#define STR_OF_BOOL(yesOrNo)     ((yesOrNo) ? @"YES" : @"NO")
// NSInteger/int/long to string
#define STR_OF_INTEGER(integer)     ([NSString stringWithFormat:@"%ld", (long)(integer)])
// float/double to string
#define STR_OF_FLOAT(f)     ([NSString stringWithFormat:@"%f", (double)(f)])


// property name to string
#define STR_OF_PROP(property)    (NSStringFromSelector(@selector(property)))
// NSRange to string
#define STR_OF_RANGE(range) (NSStringFromRange(range))

/**
 literal JSON c string to NSString

 @param ... the literal string
 @return the NSString
 @see https://stackoverflow.com/a/14293615
 @warning the `\n` will replaced by ` `
 */
#define STR_OF_JSON(...) @#__VA_ARGS__

/**
 Get string from file
 
 @param filePath the file path relative to [[NSBundle mainBundle] bundlePath]
 @return the content string of the file path
 */
#define STR_OF_FILE(filePath)   ([NSString stringWithContentsOfFile:[[[NSBundle mainBundle] bundlePath] stringByAppendingPathComponent:(filePath)] encoding:NSUTF8StringEncoding error:nil])

/// Private: for STR_OF_LITERAL macro
#define __STRINGFY(a) @#a
/**
 Get a literal string from literal text
 
 @param literal_ the literal text or a macro
 @return the literal string
 */
#define STR_OF_LITERAL(literal_) __STRINGFY(literal_)

#define STR_SAFE(str) ({ \
    id str_ = (str); \
    [str_ isKindOfClass:[NSString class]] ? str_ : @""; \
})

/**
 Get a char string which length = 1
 
 @param str the string
 @param index the location of char
 @return the char string or nil
 */
#define STR_CHAR_AT(str, index) \
({ \
    NSString *retVal__; \
    if ([(str) isKindOfClass:[NSString class]] && [(str) length]) { \
        NSRange range__ = NSMakeRange(index, 1); \
        if (range__.location >= 0 && range__.location < [(str) length]) { \
            retVal__ = [(str) substringWithRange:range__]; \
        } \
    } \
    retVal__; \
});

#pragma mark > String modidication

// Catenate two strings
#define STR_CATENATE(str1, str2) ([[NSString alloc] initWithFormat:@"%@%@", str1, str2])
// Short formated string
#define STR_FORMAT(format, ...) ([[NSString alloc] initWithFormat:format, __VA_ARGS__])
// Trim a string
#define STR_TRIM(str) ([(str) isKindOfClass:[NSString class]] ? [(NSString *)(str) stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceAndNewlineCharacterSet]] : nil)

#pragma mark > String checking
// Is a string and not empty
#ifndef STR_IF_NOT_EMPTY
#define STR_IF_NOT_EMPTY(str) ({ \
    id __str__ = (str); \
    [__str__ isKindOfClass:[NSString class]] && [(NSString *)__str__ length]; \
})
#endif

// Is a string and empty
#define STR_IF_EMPTY(str) ({ \
    id __str__ = (str); \
    [(__str__) isKindOfClass:[NSString class]] && [(NSString *)(__str__) length] == 0; \
})

// Is a string and empty after trim
#define STR_TRIM_IF_EMPTY(str)   ([(str) isKindOfClass:[NSString class]] && [[(NSString *)(str) stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceAndNewlineCharacterSet]] length] == 0)

// Is a string and not empty after trim
#define STR_TRIM_IF_NOT_EMPTY(str)   ([(str) isKindOfClass:[NSString class]] && [[(NSString *)(str) stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceAndNewlineCharacterSet]] length])

#pragma mark > String size calculation

// calculate size of single line string
// @see MBProgressHUD
#if __IPHONE_OS_VERSION_MIN_REQUIRED >= 70000
    #define STR_SIZE_OF_SINGLELINE(text, font)  [text length] > 0 ? [text sizeWithAttributes:@{ NSFontAttributeName: font }] : CGSizeZero;
#else
    #define STR_SIZE_OF_SINGLELINE(text, font)  [text length] > 0 ? [text sizeWithFont:font] : CGSizeZero;
#endif

// calculate size of multiple lines string
#if __IPHONE_OS_VERSION_MIN_REQUIRED >= 70000
    #define STR_SIZE_OF_MULTILINE(text, font, maxSize, mode)                                    \
        [text length] > 0 ? [text boundingRectWithSize:maxSize                                  \
                                               options:(NSStringDrawingUsesLineFragmentOrigin | NSStringDrawingUsesFontLeading)  \
                                            attributes:@{ NSFontAttributeName: font }           \
                                               context:nil].size                                \
                          : CGSizeZero;
#else
    #define STR_SIZE_OF_MULTILINE(text, font, maxSize, mode)    \
        [text length] > 0 ? [text sizeWithFont:font             \
                             constrainedToSize:maxSize          \
                                 lineBreakMode:mode]            \
                          : CGSizeZero;
#endif

// calculate size of multiple lines string with font parameter
// @note iOS 7+
#define XXX_STR_SIZE_OF_MULTILINE(text, font, maxSize)                                      \
    [text length] > 0 ? [text boundingRectWithSize:maxSize                                  \
                                           options:(NSStringDrawingUsesLineFragmentOrigin | NSStringDrawingUsesFontLeading)  \
                                        attributes:@{ NSFontAttributeName: font }           \
                                           context:nil].size                                \
                      : CGSizeZero;

// calculate size of multiple lines string with attr parameter
// @note iOS 7+
#define XXX_STR_SIZE_OF_MULTILINE2(text, maxSize, attr)                                     \
    [text length] > 0 ? [text boundingRectWithSize:maxSize                                  \
                                           options:(NSStringDrawingUsesLineFragmentOrigin)  \
                                        attributes:attr                                     \
                                           context:nil].size                                \
                      : CGSizeZero;

#pragma mark - String enum

/**
 Declare the enum type and enum values
 
 @param ... the first param is enum type, and others are enum values
 
 @see https://stackoverflow.com/a/34629960
 */
#define STR_ENUM_DECLARE(...) \
STR_ENUM_DECLARE_SHIFT(,##__VA_ARGS__,\
STR_ENUM_DECLARE_15(__VA_ARGS__),\
STR_ENUM_DECLARE_14(__VA_ARGS__),\
STR_ENUM_DECLARE_13(__VA_ARGS__),\
STR_ENUM_DECLARE_12(__VA_ARGS__),\
STR_ENUM_DECLARE_11(__VA_ARGS__),\
STR_ENUM_DECLARE_10(__VA_ARGS__),\
STR_ENUM_DECLARE_9(__VA_ARGS__),\
STR_ENUM_DECLARE_8(__VA_ARGS__),\
STR_ENUM_DECLARE_7(__VA_ARGS__),\
STR_ENUM_DECLARE_6(__VA_ARGS__),\
STR_ENUM_DECLARE_5(__VA_ARGS__),\
STR_ENUM_DECLARE_4(__VA_ARGS__),\
STR_ENUM_DECLARE_3(__VA_ARGS__),\
STR_ENUM_DECLARE_2(__VA_ARGS__),\
STR_ENUM_DECLARE_1(__VA_ARGS__),\
)

/**
 Define the enum type and enum values
 
 @param ... the first param is enum type, and others are enum values
 
 @see https://stackoverflow.com/a/34629960
 */
#define STR_ENUM_DEFINE(...) \
STR_ENUM_DEFINE_SHIFT(,##__VA_ARGS__,\
STR_ENUM_DEFINE_15(__VA_ARGS__),\
STR_ENUM_DEFINE_14(__VA_ARGS__),\
STR_ENUM_DEFINE_13(__VA_ARGS__),\
STR_ENUM_DEFINE_12(__VA_ARGS__),\
STR_ENUM_DEFINE_11(__VA_ARGS__),\
STR_ENUM_DEFINE_10(__VA_ARGS__),\
STR_ENUM_DEFINE_9(__VA_ARGS__),\
STR_ENUM_DEFINE_8(__VA_ARGS__),\
STR_ENUM_DEFINE_7(__VA_ARGS__),\
STR_ENUM_DEFINE_6(__VA_ARGS__),\
STR_ENUM_DEFINE_5(__VA_ARGS__),\
STR_ENUM_DEFINE_4(__VA_ARGS__),\
STR_ENUM_DEFINE_3(__VA_ARGS__),\
STR_ENUM_DEFINE_2(__VA_ARGS__),\
STR_ENUM_DEFINE_1(__VA_ARGS__),\
)

#pragma mark > String enum internal

// CONFIGURE: add p15 before FUNC
#define STR_ENUM_DECLARE_SHIFT(x,y,p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11,p12,p13,p14,p15,FUNC, ...) FUNC

// CONFIGURE: add p15 before FUNC
#define STR_ENUM_DEFINE_SHIFT(x,y,p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11,p12,p13,p14,p15,FUNC, ...) FUNC

// number of enums: 1
#define STR_ENUM_DECLARE_1(enumType_, e1_) \
extern const struct enumType_##Struct_ \
{ \
    __unsafe_unretained NSString *e1_; \
} enumType_;

#define STR_ENUM_DEFINE_1(enumType_, e1_) \
const struct enumType_##Struct_ enumType_ = \
{ \
    .e1_ = @#e1_, \
};

// number of enums: 2
#define STR_ENUM_DECLARE_2(enumType_, e1_, e2_) \
extern const struct enumType_##Struct_ \
{ \
    __unsafe_unretained NSString *e1_; \
    __unsafe_unretained NSString *e2_; \
} enumType_;

#define STR_ENUM_DEFINE_2(enumType_, e1_, e2_) \
const struct enumType_##Struct_ enumType_ = \
{ \
    .e1_ = @#e1_, \
    .e2_ = @#e2_, \
};

// number of enums: 3
#define STR_ENUM_DECLARE_3(enumType_, e1_, e2_, e3_) \
extern const struct enumType_##Struct_ \
{ \
    __unsafe_unretained NSString *e1_; \
    __unsafe_unretained NSString *e2_; \
    __unsafe_unretained NSString *e3_; \
} enumType_;

#define STR_ENUM_DEFINE_3(enumType_, e1_, e2_, e3_) \
const struct enumType_##Struct_ enumType_ = \
{ \
    .e1_ = @#e1_, \
    .e2_ = @#e2_, \
    .e3_ = @#e3_, \
};

// number of enums: 4
#define STR_ENUM_DECLARE_4(enumType_, e1_, e2_, e3_, e4_) \
extern const struct enumType_##Struct_ \
{ \
    __unsafe_unretained NSString *e1_; \
    __unsafe_unretained NSString *e2_; \
    __unsafe_unretained NSString *e3_; \
    __unsafe_unretained NSString *e4_; \
} enumType_;

#define STR_ENUM_DEFINE_4(enumType_, e1_, e2_, e3_, e4_) \
const struct enumType_##Struct_ enumType_ = \
{ \
    .e1_ = @#e1_, \
    .e2_ = @#e2_, \
    .e3_ = @#e3_, \
    .e4_ = @#e4_, \
};

// number of enums: 5
#define STR_ENUM_DECLARE_5(enumType_, e1_, e2_, e3_, e4_, e5_) \
extern const struct enumType_##Struct_ \
{ \
    __unsafe_unretained NSString *e1_; \
    __unsafe_unretained NSString *e2_; \
    __unsafe_unretained NSString *e3_; \
    __unsafe_unretained NSString *e4_; \
    __unsafe_unretained NSString *e5_; \
} enumType_;

#define STR_ENUM_DEFINE_5(enumType_, e1_, e2_, e3_, e4_, e5_) \
const struct enumType_##Struct_ enumType_ = \
{ \
    .e1_ = @#e1_, \
    .e2_ = @#e2_, \
    .e3_ = @#e3_, \
    .e4_ = @#e4_, \
    .e5_ = @#e5_, \
};

// number of enums: 6
#define STR_ENUM_DECLARE_6(enumType_, e1_, e2_, e3_, e4_, e5_, e6_) \
extern const struct enumType_##Struct_ \
{ \
    __unsafe_unretained NSString *e1_; \
    __unsafe_unretained NSString *e2_; \
    __unsafe_unretained NSString *e3_; \
    __unsafe_unretained NSString *e4_; \
    __unsafe_unretained NSString *e5_; \
    __unsafe_unretained NSString *e6_; \
} enumType_;

#define STR_ENUM_DEFINE_6(enumType_, e1_, e2_, e3_, e4_, e5_, e6_) \
const struct enumType_##Struct_ enumType_ = \
{ \
    .e1_ = @#e1_, \
    .e2_ = @#e2_, \
    .e3_ = @#e3_, \
    .e4_ = @#e4_, \
    .e5_ = @#e5_, \
    .e6_ = @#e6_, \
};

// number of enums: 7
#define STR_ENUM_DECLARE_7(enumType_, e1_, e2_, e3_, e4_, e5_, e6_, e7_) \
extern const struct enumType_##Struct_ \
{ \
    __unsafe_unretained NSString *e1_; \
    __unsafe_unretained NSString *e2_; \
    __unsafe_unretained NSString *e3_; \
    __unsafe_unretained NSString *e4_; \
    __unsafe_unretained NSString *e5_; \
    __unsafe_unretained NSString *e6_; \
    __unsafe_unretained NSString *e7_; \
} enumType_;

#define STR_ENUM_DEFINE_7(enumType_, e1_, e2_, e3_, e4_, e5_, e6_, e7_) \
const struct enumType_##Struct_ enumType_ = \
{ \
    .e1_ = @#e1_, \
    .e2_ = @#e2_, \
    .e3_ = @#e3_, \
    .e4_ = @#e4_, \
    .e5_ = @#e5_, \
    .e6_ = @#e6_, \
    .e7_ = @#e7_, \
};

// number of enums: 8
#define STR_ENUM_DECLARE_8(enumType_, e1_, e2_, e3_, e4_, e5_, e6_, e7_, e8_) \
extern const struct enumType_##Struct_ \
{ \
    __unsafe_unretained NSString *e1_; \
    __unsafe_unretained NSString *e2_; \
    __unsafe_unretained NSString *e3_; \
    __unsafe_unretained NSString *e4_; \
    __unsafe_unretained NSString *e5_; \
    __unsafe_unretained NSString *e6_; \
    __unsafe_unretained NSString *e7_; \
    __unsafe_unretained NSString *e8_; \
} enumType_;

#define STR_ENUM_DEFINE_8(enumType_, e1_, e2_, e3_, e4_, e5_, e6_, e7_, e8_) \
const struct enumType_##Struct_ enumType_ = \
{ \
    .e1_ = @#e1_, \
    .e2_ = @#e2_, \
    .e3_ = @#e3_, \
    .e4_ = @#e4_, \
    .e5_ = @#e5_, \
    .e6_ = @#e6_, \
    .e7_ = @#e7_, \
    .e8_ = @#e8_, \
};

// number of enums: 9
#define STR_ENUM_DECLARE_9(enumType_, e1_, e2_, e3_, e4_, e5_, e6_, e7_, e8_, e9_) \
extern const struct enumType_##Struct_ \
{ \
    __unsafe_unretained NSString *e1_; \
    __unsafe_unretained NSString *e2_; \
    __unsafe_unretained NSString *e3_; \
    __unsafe_unretained NSString *e4_; \
    __unsafe_unretained NSString *e5_; \
    __unsafe_unretained NSString *e6_; \
    __unsafe_unretained NSString *e7_; \
    __unsafe_unretained NSString *e8_; \
    __unsafe_unretained NSString *e9_; \
} enumType_;

#define STR_ENUM_DEFINE_9(enumType_, e1_, e2_, e3_, e4_, e5_, e6_, e7_, e8_, e9_) \
const struct enumType_##Struct_ enumType_ = \
{ \
    .e1_ = @#e1_, \
    .e2_ = @#e2_, \
    .e3_ = @#e3_, \
    .e4_ = @#e4_, \
    .e5_ = @#e5_, \
    .e6_ = @#e6_, \
    .e7_ = @#e7_, \
    .e8_ = @#e8_, \
    .e9_ = @#e9_, \
};

// number of enums: 10
#define STR_ENUM_DECLARE_10(enumType_, e1_, e2_, e3_, e4_, e5_, e6_, e7_, e8_, e9_, e10_) \
extern const struct enumType_##Struct_ \
{ \
    __unsafe_unretained NSString *e1_; \
    __unsafe_unretained NSString *e2_; \
    __unsafe_unretained NSString *e3_; \
    __unsafe_unretained NSString *e4_; \
    __unsafe_unretained NSString *e5_; \
    __unsafe_unretained NSString *e6_; \
    __unsafe_unretained NSString *e7_; \
    __unsafe_unretained NSString *e8_; \
    __unsafe_unretained NSString *e9_; \
    __unsafe_unretained NSString *e10_; \
} enumType_;

#define STR_ENUM_DEFINE_10(enumType_, e1_, e2_, e3_, e4_, e5_, e6_, e7_, e8_, e9_, e10_) \
const struct enumType_##Struct_ enumType_ = \
{ \
    .e1_ = @#e1_, \
    .e2_ = @#e2_, \
    .e3_ = @#e3_, \
    .e4_ = @#e4_, \
    .e5_ = @#e5_, \
    .e6_ = @#e6_, \
    .e7_ = @#e7_, \
    .e8_ = @#e8_, \
    .e9_ = @#e9_, \
    .e10_ = @#e10_, \
};

// number of enums: 11
#define STR_ENUM_DECLARE_11(enumType_, e1_, e2_, e3_, e4_, e5_, e6_, e7_, e8_, e9_, e10_, e11_) \
extern const struct enumType_##Struct_ \
{ \
    __unsafe_unretained NSString *e1_; \
    __unsafe_unretained NSString *e2_; \
    __unsafe_unretained NSString *e3_; \
    __unsafe_unretained NSString *e4_; \
    __unsafe_unretained NSString *e5_; \
    __unsafe_unretained NSString *e6_; \
    __unsafe_unretained NSString *e7_; \
    __unsafe_unretained NSString *e8_; \
    __unsafe_unretained NSString *e9_; \
    __unsafe_unretained NSString *e10_; \
    __unsafe_unretained NSString *e11_; \
} enumType_;

#define STR_ENUM_DEFINE_11(enumType_, e1_, e2_, e3_, e4_, e5_, e6_, e7_, e8_, e9_, e10_, e11_) \
const struct enumType_##Struct_ enumType_ = \
{ \
    .e1_ = @#e1_, \
    .e2_ = @#e2_, \
    .e3_ = @#e3_, \
    .e4_ = @#e4_, \
    .e5_ = @#e5_, \
    .e6_ = @#e6_, \
    .e7_ = @#e7_, \
    .e8_ = @#e8_, \
    .e9_ = @#e9_, \
    .e10_ = @#e10_, \
    .e11_ = @#e11_, \
};

// number of enums: 12
#define STR_ENUM_DECLARE_12(enumType_, e1_, e2_, e3_, e4_, e5_, e6_, e7_, e8_, e9_, e10_, e11_, e12_) \
extern const struct enumType_##Struct_ \
{ \
    __unsafe_unretained NSString *e1_; \
    __unsafe_unretained NSString *e2_; \
    __unsafe_unretained NSString *e3_; \
    __unsafe_unretained NSString *e4_; \
    __unsafe_unretained NSString *e5_; \
    __unsafe_unretained NSString *e6_; \
    __unsafe_unretained NSString *e7_; \
    __unsafe_unretained NSString *e8_; \
    __unsafe_unretained NSString *e9_; \
    __unsafe_unretained NSString *e10_; \
    __unsafe_unretained NSString *e11_; \
    __unsafe_unretained NSString *e12_; \
} enumType_;

#define STR_ENUM_DEFINE_12(enumType_, e1_, e2_, e3_, e4_, e5_, e6_, e7_, e8_, e9_, e10_, e11_, e12_) \
const struct enumType_##Struct_ enumType_ = \
{ \
    .e1_ = @#e1_, \
    .e2_ = @#e2_, \
    .e3_ = @#e3_, \
    .e4_ = @#e4_, \
    .e5_ = @#e5_, \
    .e6_ = @#e6_, \
    .e7_ = @#e7_, \
    .e8_ = @#e8_, \
    .e9_ = @#e9_, \
    .e10_ = @#e10_, \
    .e11_ = @#e11_, \
    .e12_ = @#e12_, \
};

// number of enums: 13
#define STR_ENUM_DECLARE_13(enumType_, e1_, e2_, e3_, e4_, e5_, e6_, e7_, e8_, e9_, e10_, e11_, e12_, e13_) \
extern const struct enumType_##Struct_ \
{ \
    __unsafe_unretained NSString *e1_; \
    __unsafe_unretained NSString *e2_; \
    __unsafe_unretained NSString *e3_; \
    __unsafe_unretained NSString *e4_; \
    __unsafe_unretained NSString *e5_; \
    __unsafe_unretained NSString *e6_; \
    __unsafe_unretained NSString *e7_; \
    __unsafe_unretained NSString *e8_; \
    __unsafe_unretained NSString *e9_; \
    __unsafe_unretained NSString *e10_; \
    __unsafe_unretained NSString *e11_; \
    __unsafe_unretained NSString *e12_; \
    __unsafe_unretained NSString *e13_; \
} enumType_;

#define STR_ENUM_DEFINE_13(enumType_, e1_, e2_, e3_, e4_, e5_, e6_, e7_, e8_, e9_, e10_, e11_, e12_, e13_) \
const struct enumType_##Struct_ enumType_ = \
{ \
    .e1_ = @#e1_, \
    .e2_ = @#e2_, \
    .e3_ = @#e3_, \
    .e4_ = @#e4_, \
    .e5_ = @#e5_, \
    .e6_ = @#e6_, \
    .e7_ = @#e7_, \
    .e8_ = @#e8_, \
    .e9_ = @#e9_, \
    .e10_ = @#e10_, \
    .e11_ = @#e11_, \
    .e12_ = @#e12_, \
    .e13_ = @#e13_, \
};

// number of enums: 14
#define STR_ENUM_DECLARE_14(enumType_, e1_, e2_, e3_, e4_, e5_, e6_, e7_, e8_, e9_, e10_, e11_, e12_, e13_, e14_) \
extern const struct enumType_##Struct_ \
{ \
    __unsafe_unretained NSString *e1_; \
    __unsafe_unretained NSString *e2_; \
    __unsafe_unretained NSString *e3_; \
    __unsafe_unretained NSString *e4_; \
    __unsafe_unretained NSString *e5_; \
    __unsafe_unretained NSString *e6_; \
    __unsafe_unretained NSString *e7_; \
    __unsafe_unretained NSString *e8_; \
    __unsafe_unretained NSString *e9_; \
    __unsafe_unretained NSString *e10_; \
    __unsafe_unretained NSString *e11_; \
    __unsafe_unretained NSString *e12_; \
    __unsafe_unretained NSString *e13_; \
    __unsafe_unretained NSString *e14_; \
} enumType_;

#define STR_ENUM_DEFINE_14(enumType_, e1_, e2_, e3_, e4_, e5_, e6_, e7_, e8_, e9_, e10_, e11_, e12_, e13_, e14_) \
const struct enumType_##Struct_ enumType_ = \
{ \
    .e1_ = @#e1_, \
    .e2_ = @#e2_, \
    .e3_ = @#e3_, \
    .e4_ = @#e4_, \
    .e5_ = @#e5_, \
    .e6_ = @#e6_, \
    .e7_ = @#e7_, \
    .e8_ = @#e8_, \
    .e9_ = @#e9_, \
    .e10_ = @#e10_, \
    .e11_ = @#e11_, \
    .e12_ = @#e12_, \
    .e13_ = @#e13_, \
    .e14_ = @#e14_, \
};

// number of enums: 15
#define STR_ENUM_DECLARE_15(enumType_, e1_, e2_, e3_, e4_, e5_, e6_, e7_, e8_, e9_, e10_, e11_, e12_, e13_, e14_, e15_) \
extern const struct enumType_##Struct_ \
{ \
    __unsafe_unretained NSString *e1_; \
    __unsafe_unretained NSString *e2_; \
    __unsafe_unretained NSString *e3_; \
    __unsafe_unretained NSString *e4_; \
    __unsafe_unretained NSString *e5_; \
    __unsafe_unretained NSString *e6_; \
    __unsafe_unretained NSString *e7_; \
    __unsafe_unretained NSString *e8_; \
    __unsafe_unretained NSString *e9_; \
    __unsafe_unretained NSString *e10_; \
    __unsafe_unretained NSString *e11_; \
    __unsafe_unretained NSString *e12_; \
    __unsafe_unretained NSString *e13_; \
    __unsafe_unretained NSString *e14_; \
    __unsafe_unretained NSString *e15_; \
} enumType_;

#define STR_ENUM_DEFINE_15(enumType_, e1_, e2_, e3_, e4_, e5_, e6_, e7_, e8_, e9_, e10_, e11_, e12_, e13_, e14_, e15_) \
const struct enumType_##Struct_ enumType_ = \
{ \
    .e1_ = @#e1_, \
    .e2_ = @#e2_, \
    .e3_ = @#e3_, \
    .e4_ = @#e4_, \
    .e5_ = @#e5_, \
    .e6_ = @#e6_, \
    .e7_ = @#e7_, \
    .e8_ = @#e8_, \
    .e9_ = @#e9_, \
    .e10_ = @#e10_, \
    .e11_ = @#e11_, \
    .e12_ = @#e12_, \
    .e13_ = @#e13_, \
    .e14_ = @#e14_, \
    .e15_ = @#e15_, \
};


//extern const struct AMPlayerStateReadable
//{
//    __unsafe_unretained NSString *ready;
//    __unsafe_unretained NSString *completed;
//    __unsafe_unretained NSString *playing;
//    __unsafe_unretained NSString *paused;
//    __unsafe_unretained NSString *broken;
//} AMPlayerState;
//
//const struct AMPlayerStateReadable AMPlayerState =
//{
//    .ready = @"READY",
//    .completed = @"COMPLETE",
//    .playing = @"PLAYING",
//    .paused = @"PAUSED",
//    .broken = @"BROKEN"
//};


#pragma mark - Pretty String

/**
 Get pretty size for memory bytes, which 1024 byte = 1 KB
 
 @param memoryBytes__ the bytes for memory
 @return the pretty size string
 */
#define STR_PRETTY_SIZE_M(memoryBytes__) ([NSByteCountFormatter stringFromByteCount:(long long)(memoryBytes__) countStyle:NSByteCountFormatterCountStyleBinary])

/**
 Get pretty size for memory bytes, which 1000 byte = 1 KB
 
 @param fileBytes__ the bytes for file
 @return the pretty size string
 */
#define STR_PRETTY_SIZE_F(fileBytes__) ([NSByteCountFormatter stringFromByteCount:(long long)(fileBytes__) countStyle:NSByteCountFormatterCountStyleDecimal];)

#endif /* WCMacroString_h */
