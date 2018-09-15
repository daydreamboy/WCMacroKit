//
//  Test_THREAD_SAFE_LAZY_GETTER_BODY_ViewController.m
//  AppTest
//
//  Created by wesley_chen on 01/03/2018.
//

#import "Test_THREAD_SAFE_LAZY_GETTER_BODY_ViewController.h"
#import "WCMacroKit.h"

@interface Test_THREAD_SAFE_LAZY_GETTER_BODY_ViewController ()
@property (nonatomic, strong) NSString *sharedString;
@end

@protocol A <NSObject>
@end

@protocol B <NSObject>
@end

@interface ModelB : NSObject <B>
@end
@implementation ModelB
- (NSString *)description {
    return [NSString stringWithFormat:@"%p: This is a object of ModelB", self];
}
@end

@interface ModelA : NSObject <A>
@property (nonatomic, strong) id<B> b;
@end
@implementation ModelA
- (instancetype)init {
    self = [super init];
    if (self) {
        _b = [ModelB new];
    }
    return self;
}
@end

@interface SomeModel : NSObject
@property (nonatomic, strong) id<A> a;
@end

@implementation SomeModel
- (instancetype)init {
    self = [super init];
    if (self) {
        _a = [ModelA new];
    }
    return self;
}
@end

@implementation Test_THREAD_SAFE_LAZY_GETTER_BODY_ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    [NSThread detachNewThreadSelector:@selector(printSharedString) toTarget:self withObject:nil];
    [NSThread detachNewThreadSelector:@selector(printSharedString) toTarget:self withObject:nil];
    [NSThread detachNewThreadSelector:@selector(printSharedString) toTarget:self withObject:nil];
    
    NSDICTIONARY_M_PAIRS_BEGIN(dictM)
    NSDICTIONARY_M_PAIRS_SET(@"key1", @"string")
    NSDICTIONARY_M_PAIRS_SET(@"key1", @YES)
    NSDICTIONARY_M_PAIRS_SET(@"key1", @1)
    NSDICTIONARY_M_PAIRS_END
    
    NSLog(@"%@", dictM);
}

- (void)test_NSOBJECT_TYPE_CONVERT {
    SomeModel *model = [SomeModel new];
    NSOBJECT_TYPE_CONVERT(varA, model.a, ModelA);
    NSOBJECT_TYPE_CONVERT(varB, varA.b, ModelB);
    ModelB *modelB = varB;
    NSLog(@"%@", modelB);
}

/*
- (NSString *)sharedString {
    NSTimeInterval timestamp = [[NSDate date] timeIntervalSince1970];
    if (!_sharedString) {
        _sharedString = [NSString stringWithFormat:@"str: %f", (double)timestamp];
    }

    return _sharedString;
}
 */

- (NSString *)sharedString {
    NSTimeInterval timestamp = [[NSDate date] timeIntervalSince1970];
    NSLog(@"now: %f", (double)timestamp);
    // Note: THREAD_SAFE_LAZY_GETTER_BODY带三个参数，后面的逗号不是参数分隔符
    THREAD_SAFE_LAZY_GETTER_BODY(sharedString,
                                 _sharedString,
                                 _sharedString = [NSString stringWithFormat:@"str: %f", (double)timestamp];
                                 )
}

#pragma mark - Thread Entry

- (void)printSharedString {
    // Note: 应该输出是一样的
    NSLog(@"%@", self.sharedString);
}

@end
