//
//  Test_STR_OF_JSONViewController.m
//  AppTest
//
//  Created by wesley_chen on 15/01/2018.
//

#import "Test_STR_OF_JSONViewController.h"
#import "WCMacroKit.h"

// json from http://json.org/example.html
static NSString *jsonString = STR_OF_JSON(
{
    "glossary": {
        "title": "example glossary",
        "GlossDiv": {
            "title": "S",
            "GlossList": {
                "GlossEntry": {
                    "ID": "SGML",
                    "SortAs": "SGML",
                    "GlossTerm": "Standard Generalized Markup Language",
                    "Acronym": "SGML",
                    "Abbrev": "ISO 8879:1986",
                    "GlossDef": {
                        "para": "A meta-markup language, used to create markup languages such as DocBook.",
                        "GlossSeeAlso": ["GML", "XML"]
                    },
                    "GlossSee": "markup"
                }
            }
        }
    }
}
);

static NSString *jsonStringWithFormat = STR_OF_JSON(
{
    "glossary": {
        "title": "%@",
        "GlossDiv": {
            "title": "%@",
        }
    }
}
);

@implementation Test_STR_OF_JSONViewController

- (void)viewDidLoad {
    [super viewDidLoad];

    [self test1];
    [self test2];
}

- (void)test1 {
    NSData *jsonData = [jsonString dataUsingEncoding:NSUTF8StringEncoding];
    NSDictionary *dict = [NSJSONSerialization JSONObjectWithData:jsonData options:kNilOptions error:nil];
    NSLog(@"dict: %@", dict);
}

- (void)test2 {
    NSString *jsonString = [NSString stringWithFormat:jsonStringWithFormat, @"This is first title", @"This is second title"];
    NSData *jsonData = [jsonString dataUsingEncoding:NSUTF8StringEncoding];
    NSDictionary *dict = [NSJSONSerialization JSONObjectWithData:jsonData options:kNilOptions error:nil];
    NSLog(@"dict: %@", dict);
}

@end
