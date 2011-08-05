/*
 *     Generated by class-dump 3.3.3 (64 bit).
 *
 *     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2010 by Steve Nygard.
 */

#import "MimeTextAttachment.h"

@class NSFileWrapper, NSImage;

@interface MailTextAttachment : MimeTextAttachment
{
    unsigned int _isPossibleToDisplayAttachmentInline:1;
    unsigned int _isPossibleToDisplayAttachmentAsView:1;
    unsigned int _isDisplayingAttachmentInline:1;
    unsigned int _shouldDisplayInlineByDefault:1;
    unsigned int _isImageBeingResized:1;
    NSFileWrapper *_originalFileWrapper;
    NSImage *_originalImage;
    struct CGSize _originalImageSize;
    struct CGSize _maxImageSize;
    struct CGSize _lastMaxImageSize;
}

+ (void)initialize;
+ (id)replacementAttachmentForAttachment:(id)arg1;
- (id)initWithMimePart:(id)arg1 andFileWrapper:(id)arg2 iconOnly:(BOOL)arg3;
- (id)initWithMimePart:(id)arg1 andFileWrapper:(id)arg2;
- (void)dealloc;
@property BOOL shouldDisplayInlineByDefault;
@property BOOL isPossibleToDisplayAttachmentInline;
@property BOOL isDisplayingAttachmentInline;
- (BOOL)hasData;
- (void)updateFromPath:(id)arg1 contentID:(id)arg2;
- (id)attachmentCell;
- (id)_getInlineImage;
- (void)_configureLabelForCell:(id)arg1;
- (id)toolTip;
@property BOOL isPartOfStationery;
- (BOOL)isPDF;
- (BOOL)isScalable;
- (BOOL)isFullSize;
- (id)_originalImage;
- (void)_setupOriginalImageIfNeeded;
- (struct CGSize)_originalImageSize;
- (id)originalFileWrapper;
- (struct CGSize)maxImageSize;
- (struct CGSize)originalImageSize;
- (void)resizingStarted:(struct CGSize)arg1;
- (void)resizingFinished:(id)arg1 imageSize:(struct CGSize)arg2 fileExtension:(id)arg3 fileType:(unsigned int)arg4 maxImageSize:(struct CGSize)arg5;

@end
