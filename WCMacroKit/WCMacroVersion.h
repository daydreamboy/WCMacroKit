//
//  WCMacroVersion.h
//  WCMacroKit
//
//  Created by wesley chen on 16/8/28.
//
//

#ifndef WCMacroVersion_h
#define WCMacroVersion_h

// Version
#pragma mark - Version

// == `version`
#ifndef SYSTEM_VERSION_EQUAL_TO
#define SYSTEM_VERSION_EQUAL_TO(v)                 ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedSame)
#endif

// > `version`
#ifndef SYSTEM_VERSION_GREATER_THAN
#define SYSTEM_VERSION_GREATER_THAN(v)             ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedDescending)
#endif

// >= `version`
#ifndef SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO
#define SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(v) ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedAscending)
#endif

// < `version`
#ifndef SYSTEM_VERSION_LESS_THAN
#define SYSTEM_VERSION_LESS_THAN(v)                ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedAscending)
#endif

// <= `version`
#ifndef SYSTEM_VERSION_LESS_THAN_OR_EQUAL_TO
#define SYSTEM_VERSION_LESS_THAN_OR_EQUAL_TO(v)    ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedDescending)
#endif

// >= `6.0`
#ifndef IOS6_OR_LATER
#define IOS6_OR_LATER          ([[[UIDevice currentDevice] systemVersion] compare:@"6.0" options:NSNumericSearch] != NSOrderedAscending)
#endif

// >= `7.0`
#ifndef IOS7_OR_LATER
#define IOS7_OR_LATER          ([[[UIDevice currentDevice] systemVersion] compare:@"7.0" options:NSNumericSearch] != NSOrderedAscending)
#endif

// >= `8.0`
#ifndef IOS8_OR_LATER
#define IOS8_OR_LATER          ([[[UIDevice currentDevice] systemVersion] compare:@"8.0" options:NSNumericSearch] != NSOrderedAscending)
#endif

// >= `8.3`
#ifndef IOS8_3_OR_LATER
#define IOS8_3_OR_LATER        ([[[UIDevice currentDevice] systemVersion] compare:@"8.3" options:NSNumericSearch] != NSOrderedAscending)
#endif

// >= `9.0`
#ifndef IOS9_OR_LATER
#define IOS9_OR_LATER          ([[[UIDevice currentDevice] systemVersion] compare:@"9.0" options:NSNumericSearch] != NSOrderedAscending)
#endif

// >= `10.0`
#ifndef IOS10_OR_LATER
#define IOS10_OR_LATER          ([[[UIDevice currentDevice] systemVersion] compare:@"10.0" options:NSNumericSearch] != NSOrderedAscending)
#endif

// >= `11.0`
#ifndef IOS11_OR_LATER
#define IOS11_OR_LATER          ([[[UIDevice currentDevice] systemVersion] compare:@"11.0" options:NSNumericSearch] != NSOrderedAscending)
#endif

// >= `12.0`
#ifndef IOS12_OR_LATER
#define IOS12_OR_LATER          ([[[UIDevice currentDevice] systemVersion] compare:@"12.0" options:NSNumericSearch] != NSOrderedAscending)
#endif

// >= `13.0`
#ifndef IOS13_OR_LATER
#define IOS13_OR_LATER          ([[[UIDevice currentDevice] systemVersion] compare:@"13.0" options:NSNumericSearch] != NSOrderedAscending)
#endif

// == `6.0`
#ifndef IOS6_ONLY
#define IOS6_ONLY              ([[[UIDevice currentDevice] systemVersion] compare:@"6.0" options:NSNumericSearch] == NSOrderedSame)
#endif

// == `7.0`
#ifndef IOS7_ONLY
#define IOS7_ONLY              ([[[UIDevice currentDevice] systemVersion] compare:@"7.0" options:NSNumericSearch] == NSOrderedSame)
#endif

// == `8.0`
#ifndef IOS8_ONLY
#define IOS8_ONLY              ([[[UIDevice currentDevice] systemVersion] compare:@"8.0" options:NSNumericSearch] == NSOrderedSame)
#endif


#endif /* WCMacroVersion_h */
