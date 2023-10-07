#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <slice.h>

int main() {
    {
    SliceIterator isl = MAKE_SLICE_ITERATOR(11);
    printf("\ninitial SliceIterator\nstart: %zu, stop: %zu, step: %lld, loc: %zu\n", isl.sl.start, isl.sl.stop_, isl.sl.step, isl.loc);
    FOR_EACH(size_t, pi, SliceIterator, &isl, SliceIterator) {
        printf("%zu, ", pi);
    }
    }

    {
    SliceIterator isl = MAKE_SLICE_ITERATOR(1, 11);
    printf("\nstart at 1\nstart: %zu, stop: %zu, step: %lld, loc: %zu\n", isl.sl.start, isl.sl.stop_, isl.sl.step, isl.loc);
    FOR_EACH(size_t, pi, SliceIterator, &isl, SliceIterator) {
        printf("%zu, ", pi);
    }
    }

    {
    SliceIterator isl = MAKE_SLICE_ITERATOR(1, 10, 11);
    printf("\nstart at 1, stop 1 early\nstart: %zu, stop: %zu, step: %lld, loc: %zu\n", isl.sl.start, isl.sl.stop_, isl.sl.step, isl.loc);
    FOR_EACH(size_t, pi, SliceIterator, &isl, SliceIterator) {
        printf("%zu, ", pi);
    }
    }

    {
    SliceIterator isl = MAKE_SLICE_ITERATOR(1, 10, 2, 11);
    printf("\nstart at 1, stop 1 early, step 2\nstart: %zu, stop: %zu, step: %lld, loc: %zu\n", isl.sl.start, isl.sl.stop_, isl.sl.step, isl.loc);
    FOR_EACH(size_t, pi, SliceIterator, &isl, SliceIterator) {
        printf("%zu, ", pi);
    }
    }

    {
    SliceIterator isl = MAKE_SLICE_ITERATOR(1, 9, 2, 11);
    printf("\nstart at 1, stop 2 early, step 2\nstart: %zu, stop: %zu, step: %lld, loc: %zu\n", isl.sl.start, isl.sl.stop_, isl.sl.step, isl.loc);
    FOR_EACH(size_t, pi, SliceIterator, &isl, SliceIterator) {
        printf("%zu, ", pi);
    }
    }

    {
    SliceIterator isl = MAKE_SLICE_ITERATOR(10, 1, -2, 11);
    printf("\nstart at 10, stop 1 early, step -2\nstart: %zu, stop: %zu, step: %lld, loc: %zu\n", isl.sl.start, isl.sl.stop_, isl.sl.step, isl.loc);
    FOR_EACH(size_t, pi, SliceIterator, &isl, SliceIterator) {
        printf("%zu, ", pi);
    }
    }

    {
    SliceIterator isl = MAKE_SLICE_ITERATOR(10, 0, -2, 11);
    printf("\nstart at 10, stop 0 early, step -2\nstart: %zu, stop: %zu, step: %lld, loc: %zu\n", isl.sl.start, isl.sl.stop_, isl.sl.step, isl.loc);
    FOR_EACH(size_t, pi, SliceIterator, &isl, SliceIterator) {
        printf("%zu, ", pi);
    }
    }

    {
    SliceIterator isl = MAKE_SLICE_ITERATOR(10, -1, -2, 11);
    printf("\nstart at 10, stop -1 early, step -2\nstart: %zu, stop: %zu, step: %lld, loc: %zu\n", isl.sl.start, isl.sl.stop_, isl.sl.step, isl.loc);
    FOR_EACH(size_t, pi, SliceIterator, &isl, SliceIterator) {
        printf("%zu, ", pi);
    }
    }

    {
    SliceIterator isl = MAKE_SLICE_ITERATOR(10, 1, -1, 11);
    printf("\nstart at 10, stop 1 early, step -1\nstart: %zu, stop: %zu, step: %lld, loc: %zu\n", isl.sl.start, isl.sl.stop_, isl.sl.step, isl.loc);
    FOR_EACH(size_t, pi, SliceIterator, &isl, SliceIterator) {
        printf("%zu, ", pi);
    }
    }

    {
    SliceIterator isl = MAKE_SLICE_ITERATOR(10, 0, -1, 11);
    printf("\nstart at 10, stop 0 early, step -1\nstart: %zu, stop: %zu, step: %lld, loc: %zu\n", isl.sl.start, isl.sl.stop_, isl.sl.step, isl.loc);
    FOR_EACH(size_t, pi, SliceIterator, &isl, SliceIterator) {
        printf("%zu, ", pi);
    }
    }

    {
    SliceIterator isl = MAKE_SLICE_ITERATOR(10, -1, -1, 11);
    printf("\nstart at 10, stop -1 early, step -1 (switch to 2\nstart: %zu, stop: %zu, step: %lld, loc: %zu\n", isl.sl.start, isl.sl.stop_, isl.sl.step, isl.loc);
    FOR_EACH(size_t, pi, SliceIterator, &isl, SliceIterator) {
        printf("%zu, ", pi);
    }
    }

    {
    SliceIterator isl = MAKE_SLICE_ITERATOR(-3, -1, 1, 11);
    printf("\nstart at 8, stop 10 early, step 1 (switch to 2\nstart: %zu, stop: %zu, step: %lld, loc: %zu\n", isl.sl.start, isl.sl.stop_, isl.sl.step, isl.loc);
    FOR_EACH(size_t, pi, SliceIterator, &isl, SliceIterator) {
        printf("%zu, ", pi);
    }
    }

    {
    SliceIterator isl = MAKE_SLICE_ITERATOR(-5, -3, 1, 11);
    printf("\nstart at 6, stop 8 early, step 1 (switch to 2\nstart: %zu, stop: %zu, step: %lld, loc: %zu\n", isl.sl.start, isl.sl.stop_, isl.sl.step, isl.loc);
    FOR_EACH(size_t, pi, SliceIterator, &isl, SliceIterator) {
        printf("%zu, ", pi);
    }
    }

    {
    SliceIterator isl = MAKE_SLICE_ITERATOR(-3, -5, -1, 11);
    printf("\nstart at 8, stop 6 early, step -1 (switch to 2\nstart: %zu, stop: %zu, step: %lld, loc: %zu\n", isl.sl.start, isl.sl.stop_, isl.sl.step, isl.loc);
    FOR_EACH(size_t, pi, SliceIterator, &isl, SliceIterator) {
        printf("%zu, ", pi);
    }
    }

    printf("\nSuccessful. Exiting...\n");
    
    return 0;
}