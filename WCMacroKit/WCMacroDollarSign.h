//
//  WCMacroDollarSign.h
//  WCMacroKit
//
//  Created by wesley_chen on 2019/9/2.
//

#ifndef WCMacroDollarSign_h
#define WCMacroDollarSign_h

#import "WCMacroSafeValue.h"

// $ allowed in macro identifier in some compiler like llvm
// @see https://stackoverflow.com/questions/369495/what-are-the-valid-characters-for-macro-names
#pragma mark - $xxx as alias

/**
 Alias for DICT_SAFE_WRAP
 */
#define $dict(...) DICT_SAFE_WRAP(__VA_ARGS__)

/**
 Alias for NSARRAY_SAFE_WRAP
 */
#define $arr(...) NSARRAY_SAFE_WRAP(__VA_ARGS__)

#endif /* WCMacroDollarSign_h */
