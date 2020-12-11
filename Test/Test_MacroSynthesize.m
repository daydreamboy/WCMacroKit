//
//  Test_MacroSynthesize.m
//  Test
//
//  Created by wesley_chen on 2019/5/22.
//

#import <XCTest/XCTest.h>
#import <WCMacroKit/WCMacroKit.h>

@protocol DummyProtocol <NSObject>
@property (nonatomic, copy) NSString *property1;
@property (nonatomic, copy) NSString *property2;
@property (nonatomic, copy) NSString *property3;
@property (nonatomic, copy) NSString *property4;
@property (nonatomic, copy) NSString *property5;
@property (nonatomic, copy) NSString *property6;
@property (nonatomic, copy) NSString *property7;
@property (nonatomic, assign, class) CGFloat globalWidth;
@property (nonatomic, assign, class) NSString *globalName;
@end

@interface Test_MacroSynthesize : XCTestCase <DummyProtocol>
@end

@implementation Test_MacroSynthesize
SYNTHESIZE_PROPERTYS(property1, property2, property3, property4, property5, property6, property7);
SYNTHESIZE_CLASS_PROPERTY_PRIMITIVE(globalWidth, setGlobalWidth, CGFloat);
SYNTHESIZE_CLASS_PROPERTY_OBJECT(globalName, setGlobalName, NSString *);

- (void)setUp {
    NSLog(@"\n");
}

- (void)tearDown {
    NSLog(@"\n");
}

- (void)test {
    for (NSInteger i = 1; i <= 7; i++) {
        NSString *key = [NSString stringWithFormat:@"property%d", (int)i];
        [self setValue:[NSString stringWithFormat:@"%d", (int)i] forKey:key];
    }
    
    XCTAssertEqualObjects(self.property1, @"1");
    XCTAssertEqualObjects(self.property2, @"2");
    XCTAssertEqualObjects(self.property3, @"3");
    XCTAssertEqualObjects(self.property4, @"4");
    XCTAssertEqualObjects(self.property5, @"5");
    XCTAssertEqualObjects(self.property6, @"6");
    XCTAssertEqualObjects(self.property7, @"7");
}

- (void)test_SYNTHESIZE_CLASS_PROPERTY_PRIMITIVE {
    Test_MacroSynthesize.globalWidth = 300.0;
    NSLog(@"%f", Test_MacroSynthesize.globalWidth);
}

- (void)test_SYNTHESIZE_CLASS_PROPERTY_OBJECT {
    Test_MacroSynthesize.globalName = @"Test_MacroSynthesize";
    NSLog(@"%@", Test_MacroSynthesize.globalName);
}

@end
