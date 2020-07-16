//
//  WCMacroAttributedString.h
//  WCMacroKit
//
//  Created by wesley_chen on 2020/7/15.
//

#ifndef WCMacroAttributedString_h
#define WCMacroAttributedString_h

#pragma mark - Immutable

/**
 Create an immutable attributed string
 
 @param the string
 @return the attributed string
 */
#define ASTR(str) ([[NSAttributedString alloc] initWithString:[(id)(str) isKindOfClass:[NSString class]] ? (id)(str) : @""])

/**
 Create an immutable attributed string with attributes
 
 @param the string
 @param the attributes dictionary
 @return the attributed string
 */
#define ASTR2(str, attrs) ([[NSAttributedString alloc] initWithString:([(id)(str) isKindOfClass:[NSString class]] ? (id)(str) : @"") attributes:([(id)(attrs) isKindOfClass:[NSDictionary class]] ? (id)(attrs) : @{})])

#pragma mark - Mutable

/**
 Create a mutable attributed string
 
 @param the string
 @return the attributed string
 */
#define ASTR_M(str) ([[NSMutableAttributedString alloc] initWithString:[(id)(str) isKindOfClass:[NSString class]] ? (id)(str) : @""])

/**
 Create a mutable attributed string with attributes
 
 @param the string
 @param the attributes dictionary
 @return the attributed string
 */
#define ASTR2_M(str, attrs) ([[NSMutableAttributedString alloc] initWithString:[(id)(str) isKindOfClass:[NSString class]] ? (id)(str) : @""] attributes:[(id)(attrs) isKindOfClass:[NSDictionary class]] ? (id)(attrs) : @{}]])

/**
 Create a new attributed string which catenat str1 and str2
 
 @param the attributed string1
 @param the attributed string2
 @return the new attributed string
 */
#define ASTR_M_CATENATE(str1, str2) \
({ \
    NSMutableAttributedString *__return_attrString = [[NSMutableAttributedString alloc] initWithAttributedString:[(id)(str1) isKindOfClass:[NSAttributedString class]] ? (id)(str1) : ASTR_M(@"")]]; \
    [__return_attrString appendAttributedString:[(id)(str2) isKindOfClass:[NSAttributedString class]] ? (id)(str2) : ASTR_M(@"")]]; \
    __return_attrString; \
})

#endif /* WCMacroAttributedString_h */
