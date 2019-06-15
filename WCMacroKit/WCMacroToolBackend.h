//
//  WCMacroToolBackend.h
//  WCMacroKit
//
//  Created by wesley_chen on 2019/3/9.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface WCMacroToolBackend : NSObject

/**
 Get an array from va_list

 @param ap the va_list
 @return the NSArray
 @discussion If the va_list is nil, will return an empty array
 */
+ (NSArray *)arrayFromVaList:(va_list)ap;

#pragma mark - NSDictionary

/**
 Merge two dictionaries
 
 @param dictionary1 the dictionary 1, and allow nil
 @param dictionary2 the dictionary 2, and allow nil
 @param allowMutable YES to return a mutable dictionary, NO to return an immutable dictionary
 @return the merged dictionary. Return nil if dictionary1 and dictionary2 are not NSDictionary object
 @sa +[WCDictionaryTool mergedDictionaryWithDictionary1:dictionary2:allowMutable:]
 */
+ (nullable NSDictionary *)mergedDictionaryWithDictionary1:(nullable NSDictionary *)dictionary1 dictionary2:(nullable NSDictionary *)dictionary2 allowMutable:(BOOL)allowMutable;

@end

NS_ASSUME_NONNULL_END
