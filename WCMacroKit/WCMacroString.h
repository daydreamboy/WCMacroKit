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

#pragma mark > String modidication

// Catenate two strings
#define STR_CATENATE(str1, str2) ([NSString stringWithFormat:@"%@%@", str1, str2])
// Short formated string
#define STR_FORMAT(format, ...) ([NSString stringWithFormat:format, __VA_ARGS__])
// Trim a string
#define STR_TRIM(str) ([(str) isKindOfClass:[NSString class]] ? [(NSString *)(str) stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceAndNewlineCharacterSet]] : nil)

#pragma mark > String checking
// Is a string and not empty
#define STR_IF_NOT_EMPTY(str)    ([(str) isKindOfClass:[NSString class]] && [(NSString *)(str) length])

// Is a string and empty
#define STR_IF_EMPTY(str)        ([(str) isKindOfClass:[NSString class]] && [(NSString *)(str) length] == 0)

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
