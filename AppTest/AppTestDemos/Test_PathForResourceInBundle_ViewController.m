//
//  Test_PathForResourceInBundle_ViewController.m
//  AppTest
//
//  Created by wesley_chen on 2018/7/28.
//

#import "Test_PathForResourceInBundle_ViewController.h"
#import "WCMacroKit.h"

@interface Test_PathForResourceInBundle_ViewController ()

@end

@implementation Test_PathForResourceInBundle_ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor whiteColor];
    
    NSString *path;
    
    path = PathForResourceInBundle(@"Info.plist", nil);
    NSLog(@"%@", path);
}

@end
