#include <stdio.h>
#include <slice.h>

// need to review how I did this in ContainerLibs

int SliceIterator_iter(void * islice_in, void * islice_out_) {
    printf("creating a new SliceIterator from another SliceIterator\n");
    if (!islice_in || !islice_out_) {
        return ITERATOR_FAIL;
    }
    SliceIterator * islice_out = (SliceIterator *) islice_out_;
    *islice_out = *((SliceIterator *)islice_in);
    islice_out->loc = islice_out->sl.start;
    //printf("start: %zu, stop: %zu, step: %lld, loc: %zu, stop: %d\n", islice_out->sl.start, islice_out->sl.stop, islice_out->sl.step, islice_out->loc, islice_out->stop_);
    return ITERATOR_GO;
}
int SliceIterator_next(void * islice_, void * el) {
    SliceIterator * islice = (SliceIterator *) islice_;
    if (!islice) {
        return ITERATOR_FAIL;
    }
    if (islice->sl.step > 0) { // forward slice, start is inclusive, stop is exclusive, 
        if (islice->loc == islice->sl.stop_) {
            return ITERATOR_STOP;
        }
        *((size_t *) el) = islice->loc;
        if (islice->sl.stop_ < islice->sl.step || islice->sl.stop_ - islice->sl.step < islice->loc) { // increment loc will pass stop_
            islice->loc = islice->sl.stop_; // next call to SliceIterator_next will stop;
        } else {
            islice->loc += islice->sl.step;
        }
    } else { // reverse slice, start is exclusive, stop is inclusive
        if (islice->loc == islice->sl.start) {
            if (islice->loc == islice->sl.stop_) {
                return ITERATOR_STOP;
            }
            islice->loc -= 1;
            *((size_t *) el) = islice->loc;
            return ITERATOR_GO;
        }
        if (islice->loc < -islice->sl.step || (islice->loc > islice->sl.stop_ && islice->loc + islice->sl.step <= islice->sl.stop_)) {
            islice->loc = islice->sl.stop_; // not strictly necessary
            return ITERATOR_STOP;
        }
        islice->loc += islice->sl.step;
        *((size_t *) el) = islice->loc;
    }
    return 0;
}