//
//  TestRawStringWithC++11ViewController.m
//  AppTest
//
//  Created by wesley_chen on 15/01/2018.
//

#import "TestRawStringWithC++11ViewController.h"

// @see https://stackoverflow.com/questions/9025004/string-literals-without-having-to-escape-special-characters
// json from http://json.org/example.html
static NSString *jsonString = @R"JSON(
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
)JSON";

@implementation TestRawStringWithC__11ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    NSData *jsonData = [jsonString dataUsingEncoding:NSUTF8StringEncoding];
    NSDictionary *dict = [NSJSONSerialization JSONObjectWithData:jsonData options:kNilOptions error:nil];
    NSLog(@"dict: %@", dict);
}

@end
