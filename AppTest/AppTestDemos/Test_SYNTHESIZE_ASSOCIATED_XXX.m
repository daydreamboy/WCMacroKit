//
//  Test_SYNTHESIZE_ASSOCIATED_XXX.m
//  WCMacroKit
//
//  Created by wesley chen on 16/9/23.
//
//

#import "Test_SYNTHESIZE_ASSOCIATED_XXX.h"
#import <WCMacroKit/WCMacroKit.h>
#import <objc/runtime.h>

typedef void(^WCNavigatorCompletionBlock)(void);

@interface Test_SYNTHESIZE_ASSOCIATED_XXX ()
// Objects
@property (nonatomic, strong) NSString *associatedString;
@property (nonatomic, copy) WCNavigatorCompletionBlock associatedBlock;

// Primitives
@property (nonatomic, assign) NSInteger nsIntegerNum;
@property (nonatomic, assign) CGFloat cgFloatNum;
@property (nonatomic, assign) int intNum;
@property (nonatomic, assign) float floatNum;
@property (nonatomic, assign) CGRect cgRect;
@property (nonatomic, assign) CGSize cgSize;
@property (nonatomic, assign) CGPoint cgPoint;
@property (nonatomic, assign) NSRange nsRange;
@property (nonatomic, assign) UIEdgeInsets insets;

@property (nonatomic, assign) NSInteger nsIntegerNum_uninitialized;
@property (nonatomic, assign) CGFloat cgFloatNum_uninitialized;
@property (nonatomic, assign) int intNum_uninitialized;
@property (nonatomic, assign) float floatNum_uninitialized;
@property (nonatomic, assign) CGRect cgRect_uninitialized;
@property (nonatomic, assign) CGSize cgSize_uninitialized;
@property (nonatomic, assign) CGPoint cgPoint_uninitialized;
@property (nonatomic, assign) NSRange nsRange_uninitialized;
@property (nonatomic, assign) UIEdgeInsets insets_uninitialized;

@end

@implementation Test_SYNTHESIZE_ASSOCIATED_XXX

// Objects
SYNTHESIZE_ASSOCIATED_OBJ(associatedString, setAssociatedString, NSString *);
SYNTHESIZE_ASSOCIATED_OBJ(associatedBlock, setAssociatedBlock, WCNavigatorCompletionBlock);

// Primitives
SYNTHESIZE_ASSOCIATED_PRIMITIVE(nsIntegerNum, setNsIntegerNum, NSInteger);
SYNTHESIZE_ASSOCIATED_PRIMITIVE(cgFloatNum, setCgFloatNum, CGFloat);
SYNTHESIZE_ASSOCIATED_PRIMITIVE(intNum, setIntNum, int);
SYNTHESIZE_ASSOCIATED_PRIMITIVE(floatNum, setFloatNum, float);
SYNTHESIZE_ASSOCIATED_PRIMITIVE(cgRect, setCgRect, CGRect);
SYNTHESIZE_ASSOCIATED_PRIMITIVE(cgSize, setCgSize, CGSize);
SYNTHESIZE_ASSOCIATED_PRIMITIVE(cgPoint, setCgPoint, CGPoint);
SYNTHESIZE_ASSOCIATED_PRIMITIVE(nsRange, setNsRange, NSRange);
SYNTHESIZE_ASSOCIATED_PRIMITIVE(insets, setInsets, UIEdgeInsets);

// Primitives (uninitialized)
SYNTHESIZE_ASSOCIATED_PRIMITIVE(nsIntegerNum_uninitialized, setNsIntegerNum_uninitialized, NSInteger);
SYNTHESIZE_ASSOCIATED_PRIMITIVE(cgFloatNum_uninitialized, setCgFloatNum_uninitialized, CGFloat);
SYNTHESIZE_ASSOCIATED_PRIMITIVE(intNum_uninitialized, setIntNum_uninitialized, int);
SYNTHESIZE_ASSOCIATED_PRIMITIVE(floatNum_uninitialized, setFloatNum_uninitialized, float);
SYNTHESIZE_ASSOCIATED_PRIMITIVE(cgRect_uninitialized, setCgRect_uninitialized, CGRect);
SYNTHESIZE_ASSOCIATED_PRIMITIVE(cgSize_uninitialized, setCgSize_uninitialized, CGSize);
SYNTHESIZE_ASSOCIATED_PRIMITIVE(cgPoint_uninitialized, setCgPoint_uninitialized, CGPoint);
SYNTHESIZE_ASSOCIATED_PRIMITIVE(nsRange_uninitialized, setNsRange_uninitialized, NSRange);
SYNTHESIZE_ASSOCIATED_PRIMITIVE(insets_uninitialized, setInsets_uninitialized, UIEdgeInsets);

- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor whiteColor];
    
    [self fillData];
}

- (void)viewDidAppear:(BOOL)animated {
    [super viewDidAppear:animated];
    
    [self printData];
    NSLog(@"\n\n");
    [self printUninitializedData];
    NSLog(@"\n\n");
    
    CGRect rect;
    NSLog(@"rect: %@", NSStringFromCGRect(rect)); // CAUTION! rect is not CGRectZero
}

#pragma mark

- (void)fillData {
    self.associatedString = @"String";
    WCNavigatorCompletionBlock block = ^(void) {};
    self.associatedBlock = block;
    
    NSInteger integer = 10;
    self.nsIntegerNum = integer;
    CGFloat pi = 3.14f;
    self.cgFloatNum = pi;
    self.intNum = 1;
    self.floatNum = 3.14f;
    self.cgRect = CGRectMake(0, 0, 200, 200);
    self.cgSize = CGSizeMake(320, 640);
    self.cgPoint = CGPointMake(100, 100);
    self.nsRange = NSMakeRange(1, 3);
    self.insets = UIEdgeInsetsMake(-10, -10, -10, -10);
}

- (void)printData {
    NSLog(@"%@", self.associatedString);
    NSLog(@"%@", self.associatedBlock);
    NSLog(@"%ld", (long)self.nsIntegerNum);
    NSLog(@"%f", self.cgFloatNum);
    NSLog(@"%d", self.intNum);
    NSLog(@"%f", self.floatNum);
    NSLog(@"%@", NSStringFromCGRect(self.cgRect));
    NSLog(@"%@", NSStringFromCGSize(self.cgSize));
    NSLog(@"%@", NSStringFromCGPoint(self.cgPoint));
    NSLog(@"%@", NSStringFromRange(self.nsRange));
    NSLog(@"%@", NSStringFromUIEdgeInsets(self.insets));
}

- (void)printUninitializedData {
    NSLog(@"%ld", (long)self.nsIntegerNum_uninitialized);               // 0
    NSLog(@"%f", self.cgFloatNum_uninitialized);                        // 0.000000
    NSLog(@"%d", self.intNum_uninitialized);                            // 0
    NSLog(@"%f", self.floatNum_uninitialized);                          // 0.000000
    NSLog(@"%@", NSStringFromCGRect(self.cgRect_uninitialized));        // {{0, 0}, {0, 0}}
    NSLog(@"%@", NSStringFromCGSize(self.cgSize_uninitialized));        // {0, 0}
    NSLog(@"%@", NSStringFromCGPoint(self.cgPoint_uninitialized));      // {0, 0}
    NSLog(@"%@", NSStringFromRange(self.nsRange_uninitialized));        // {0, 0}
    NSLog(@"%@", NSStringFromUIEdgeInsets(self.insets_uninitialized));  // {0, 0, 0, 0}
}

@end
