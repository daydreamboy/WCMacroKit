//
//  WCMacroCompatibility.h
//  WCMacroKit
//
//  Created by wesley_chen on 15/11/2017.
//

#ifndef WCMacroCompatibility_h
#define WCMacroCompatibility_h

#pragma mark Compatible with lower compiler iOS SDK

// NSAttributedStringKey available on iOS 11+
#if __IPHONE_OS_VERSION_MAX_ALLOWED < 110000
#define NSAttributedStringKey   (NSString *)
#endif

#endif /* WCMacroCompatibility_h */
