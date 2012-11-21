//
//  PSPDFLabelParser.h
//  PSPDFKit
//
//  Copyright (c) 2012 Peter Steinberger. All rights reserved.
//
//  Special thanks to Cédric Luthi for providing the code.
//

#import "PSPDFKitGlobal.h"

@class PSPDFDocumentProvider;

/// Parses Page Labels (see PDF Reference §8.3.1)
/// Add custom labels with Adobe Acrobat.
/// http://www.w3.org/WAI/GL/WCAG20-TECHS/PDF17.html
@interface PSPDFLabelParser : NSObject

/// Init label parser with document provider.
- (id)initWithDocumentProvider:(PSPDFDocumentProvider *)documentProvider;

/// Attached document provider.
@property (nonatomic, weak, readonly) PSPDFDocumentProvider *documentProvider;

/// Parse document, returns labels (NSStrings)
- (NSDictionary *)parseDocument;

/// Returns a page label for a certain page. Returns nil if no pageLabel is available.
- (NSString *)pageLabelForPage:(NSUInteger)page;

/// Search all page labels for a matching page. Returns NSNotFound if page not found.
/// If partialMatching is enabled, the most likely page match is returned.
- (NSUInteger)pageForPageLabel:(NSString *)pageLabel partialMatching:(BOOL)partialMatching;

/// Returns page labels. Starts parsing if labels are not yet created.
/// NSNumber -> NSString
@property (nonatomic, copy, readonly) NSDictionary *labels;

@end
