#import <Foundation/Foundation.h>
#import <AppKit/AppKit.h>

int 
main(int argc, const char* argv[])
{
NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
[NSApplication sharedApplication];


NSRect rect;
rect = NSMakeRect(32,32,800,660);

unsigned int winStyle=
NSTitledWindowMask|
NSClosableWindowMask|
NSMiniaturizableWindowMask|
NSResizableWindowMask;

NSWindow *window = [NSWindow alloc];
[window initWithContentRect:rect
styleMask:winStyle
backing:NSBackingStoreBuffered 
defer:NO];
[window makeKeyAndOrderFront:nil];
[window makeMainWindow];


[NSApp run];
return 0;
}
