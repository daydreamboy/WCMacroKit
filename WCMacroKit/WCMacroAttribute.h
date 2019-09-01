//
//  WCMacroAttribute.h
//  WCMacroKit
//
//  Created by wesley_chen on 2019/9/1.
//

#ifndef WCMacroAttribute_h
#define WCMacroAttribute_h

#pragma mark - WC_RESTRICT_SUBCLASSING

/**
 WC_RESTRICT_SUBCLASSING
 
 Disable the class for subclassing
 */
#if defined(__has_attribute) && __has_attribute(objc_subclassing_restricted)
#define WC_RESTRICT_SUBCLASSING __attribute__((objc_subclassing_restricted))
#else
#define WC_RESTRICT_SUBCLASSING
#endif

#endif /* WCMacroAttribute_h */
