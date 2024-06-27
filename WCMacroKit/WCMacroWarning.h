//
//  WCMacroWarning.h
//  WCMacroKit
//
//  Created by wesley_chen on 2024/6/27.
//

#ifndef WCMacroWarning_h
#define WCMacroWarning_h

#pragma mark - Suppress Warning

#define SuppressPerformSelectorLeakWarning(...) \
  do { \
      _Pragma("clang diagnostic push") \
      _Pragma("clang diagnostic ignored \"-Warc-performSelector-leaks\"") \
      __VA_ARGS__; \
      _Pragma("clang diagnostic pop") \
  } while (0)


#endif /* WCMacroWarning_h */
