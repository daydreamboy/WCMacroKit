//
//  WCMacroTool.h
//  WCMacroKit
//
//  Created by wesley_chen on 2019/3/9.
//

#ifndef WCMacroTool_h
#define WCMacroTool_h

#if __has_include(<WCMacroKit/WCMacroToolBackend.h>)
#import <WCMacroKit/WCMacroToolBackend.h>
#else
#import "WCMacroToolBackend.h"
#endif

#pragma mark - va_list to NSArray

/**
 Convert va_list to NSArray

 @param _theFirst the first parameter which followed by variable arguments
 @return the array from va_list
 @see https://stackoverflow.com/a/449721
 @code
 - (void)someMethod:(NSString *)sql, ...
 {
    NSArray *args = NSArrayFromVaList(sql);
    // Do stuff with args
 }
 @endcode
 */
#define NSArrayFromVaList(_theFirst) ({ \
    va_list ap; \
    va_start(ap, _theFirst); \
    NSArray *__args = [WCMacroToolBackend arrayFromVaList:ap]; \
    va_end(ap); \
    __args; \
})

#pragma mark - NSDictionary Operation

#pragma mark > Merge

#define DICT_MERGE(dict1, dict2)    [WCMacroToolBackend mergedDictionaryWithDictionary1:(dict1) dictionary2:(dict2) allowMutable:NO]
#define DICT_MERGE_M(dict1, dict2)  (NSMutableDictionary *)[WCMacroToolBackend mergedDictionaryWithDictionary1:(dict1) dictionary2:(dict2) allowMutable:YES]

#endif /* WCMacroTool_h */
