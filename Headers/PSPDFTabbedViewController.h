//
//  PSPDFTabbedViewController.h
//  PSPDFKit
//
//  Copyright (c) 2012-2013 Peter Steinberger. All rights reserved.
//

#import "PSPDFKitGlobal.h"
#import "PSPDFMultiDocumentViewController.h"

@class PSPDFTabbedViewController, PSPDFTabBarView;

/// Delegate for the PSPDFTabbedViewController.
@protocol PSPDFTabbedViewControllerDelegate <PSPDFMultiDocumentViewControllerDelegate>
@optional

/// Will be called when the documents array changes.
- (BOOL)tabbedPDFController:(PSPDFTabbedViewController *)tabbedPDFController shouldChangeDocuments:(NSArray *)newDocuments;

/// Will be called after the documents array changed.
- (void)tabbedPDFController:(PSPDFTabbedViewController *)tabbedPDFController didChangeDocuments:(NSArray *)oldDocuments;

/// Will be called when the visibleDocument changes.
- (BOOL)tabbedPDFController:(PSPDFTabbedViewController *)tabbedPDFController shouldChangeVisibleDocument:(PSPDFDocument *)newDocument;

/// Will be called after the visibleDocument changed.
- (void)tabbedPDFController:(PSPDFTabbedViewController *)tabbedPDFController didChangeVisibleDocument:(PSPDFDocument *)oldDocument;

/// Delegate that will be called after shouldChangeDocuments if the close button has been invoked.
- (BOOL)tabbedPDFController:(PSPDFTabbedViewController *)tabbedPDFController shouldCloseDocument:(PSPDFDocument *)closedDocument;

/// Delegate that will be called after didChangeDocuments if the close button has been invoked.
- (void)tabbedPDFController:(PSPDFTabbedViewController *)tabbedPDFController didCloseDocument:(PSPDFDocument *)closedDocument;

@end

/// Allows displaying multiple PSPDFDocuments, easily switchable via a top tab bar.
@interface PSPDFTabbedViewController : PSPDFMultiDocumentViewController

/// Initialize the controller.
/// Set a custom pdfViewController to use a subclass. If nil, a default instance will be created.
- (id)initWithPDFViewController:(PSPDFViewController *)pdfController;

/// Add one or multiple documents to the documents array at the specified index.
/// Documents that are already within documents (or are equal to those) are ignored.
/// If index is invalid or NSUIntegerMax they're appended at the end.
/// Note: animated is a placeholder, doesn't yet animate.
- (void)addDocuments:(NSArray *)documents atIndex:(NSUInteger)index animated:(BOOL)animated;

/// Removes one or multiple documents to the documents array.
/// Documents that are not in the documents array will be ignored.
/// Note: animated is a placeholder, doesn't yet animate.
- (void)removeDocuments:(NSArray *)documents animated:(BOOL)animated;

/// Delegate to capture events.
@property (nonatomic, weak) IBOutlet id<PSPDFTabbedViewControllerDelegate> delegate;

/// Defaults to kPSPDFTabbedDocumentsPersistKey.
/// Change if you use multiple instances of PSPDFTabbedViewController.
@property (nonatomic, copy) NSString *statePersistanceKey;

/// Minimum tab width. Defaults to 100.
@property (nonatomic, assign) CGFloat minTabWidth;

/// Tab bar view.
@property (nonatomic, strong, readonly) PSPDFTabBarView *tabBar;

@end
