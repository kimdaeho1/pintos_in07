/* anon.c: Implementation of page for non-disk image (a.k.a. anonymous page). */

#include "vm/vm.h"
#include "devices/disk.h"

/* DO NOT MODIFY BELOW LINE */
static struct disk *swap_disk;
static bool anon_swap_in (struct page *page, void *kva);
static bool anon_swap_out (struct page *page);
static void anon_destroy (struct page *page);

/* DO NOT MODIFY this struct */
static const struct page_operations anon_ops = {
	.swap_in = anon_swap_in,
	.swap_out = anon_swap_out,
	.destroy = anon_destroy,
	.type = VM_ANON,
};

/* Initialize the data for anonymous pages */
void
vm_anon_init (void) {
	// /**/printf("------- vm_anon_init -------\n");
	/* TODO: Set up the swap_disk. */
	swap_disk = NULL;
	// /**/printf("------- vm_anon_init end -------\n");
}

/* Initialize the file mapping */
bool
anon_initializer (struct page *page, enum vm_type type, void *kva) {
	// /**/printf("------- anon_initializer -------\n");
	/* Set up the handler */
	page->operations = &anon_ops;

	struct anon_page *anon_page = &page->anon;
	// /**/printf("------- anon_initializer end -------\n");
}

/* Swap in the page by read contents from the swap disk. */
static bool
anon_swap_in (struct page *page, void *kva) {
	// /**/printf("------- anon_swap_in -------\n");
	struct anon_page *anon_page = &page->anon;
	// /**/printf("------- anon_swap_in end -------\n");
}

/* Swap out the page by writing contents to the swap disk. */
static bool
anon_swap_out (struct page *page) {
	// /**/printf("------- anon_swap_out -------\n");
	struct anon_page *anon_page = &page->anon;
	// frame table에서
	// /**/printf("------- anon_swap_out end -------\n");
}

/* Destroy the anonymous page. PAGE will be freed by the caller. */
static void
anon_destroy (struct page *page) {
	// /**/printf("------- anon_destroy -------\n");
	struct anon_page *anon_page = &page->anon;
	
	// mytodo : destroy코드 필요? (있든 없든 결과는 같음. <24.10.11 anonymous 작성중>)

	// /** Project 3: Anonymous Page - 점거중인 frame 삭제 */
	if (page->frame) {
		list_remove(&page->frame->elem);
		page->frame->page = NULL;
		free(page->frame);
		page->frame = NULL;
	}

	// /**/printf("------- anon_destroy end -------\n");
}
