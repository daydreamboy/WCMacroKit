//
//  AppDelegate.m
//  AppTest
//
//  Created by wesley chen on 16/8/28.
//
//

#import "AppDelegate.h"

#import "RootViewController.h"
#import <WCMacroKit/WCMacroKit.h>

@interface AppDelegate ()
@property (nonatomic, strong) RootViewController *rootViewController;
@property (nonatomic, strong) UINavigationController *navController AVAILABLE_IOS_APP_VERSION(2_1_10); // available on iOS app 2.1.10+
@end

@implementation AppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    self.window = [[UIWindow alloc] initWithFrame:[[UIScreen mainScreen] bounds]];
    
    self.rootViewController = [RootViewController new];
    self.navController = [[UINavigationController alloc] initWithRootViewController:self.rootViewController];
    self.window.rootViewController = self.navController;
    
    [self.window makeKeyAndVisible];
    
    NSLog(@"%@", NSStringFromCGRect([UIScreen mainScreen].bounds));
    NSLog(@"%f", [UIScreen mainScreen].scale);
    [self checkiPhoneModel];
    
    return YES;
}

- (void)checkiPhoneModel {
    if (IS_IPHONE_X_OR_XS) {
        NSLog(@"is iPhone X or iPhone XS");
    }
    else if (IS_IPHONE_XS_MAX) {
        NSLog(@"is iPhone XS Max");
    }
    else if (IS_IPHONE_XR) {
        NSLog(@"is iPhone XR");
    }
    else {
        NSLog(@"unknown device");
    }
}

@end

