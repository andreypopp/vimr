/**
 * Tae Won Ha - http://taewon.de - @hataewon
 * See LICENSE
 */

@import Cocoa;


@protocol NeoVimUiBridgeProtocol;
@class NeoVimBuffer;
@class NeoVimTab;
@class NeoVimWindow;


NS_ASSUME_NONNULL_BEGIN

@interface NeoVimAgent : NSObject

@property (nonatomic) bool useInteractiveZsh;
@property (nonatomic, weak) id <NeoVimUiBridgeProtocol> bridge;

- (instancetype)initWithUuid:(NSString *)uuid;
- (void)quit;

- (bool)runLocalServerAndNeoVim;

- (void)vimCommand:(NSString *)string;
- (NSString *)vimCommandOutput:(NSString *)string;

- (void)vimInput:(NSString *)string;
- (void)vimInputMarkedText:(NSString *_Nonnull)markedText;
- (void)deleteCharacters:(NSInteger)count;

- (void)resizeToWidth:(int)width height:(int)height;

- (bool)hasDirtyDocs;
- (NSString *)escapedFileName:(NSString *)fileName;
- (NSArray<NSString *> *)escapedFileNames:(NSArray<NSString *> *)fileNames;
- (NSArray<NeoVimBuffer *> *)buffers;
- (NSArray<NeoVimTab*> *)tabs;
- (bool)boolOption:(NSString *)option;
- (void)setBoolOption:(NSString *)option to:(bool)value;
- (void)selectWindow:(NeoVimWindow *)window;

@end

NS_ASSUME_NONNULL_END
