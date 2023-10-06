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
    if (((islice_out->sl.start == islice_out->sl.stop_) && (islice_out->sl.step > 0)) || islice_out->sl.step == 0) {
        islice_out->stop_ = ITERATOR_STOP;
    } else {
        islice_out->stop_ = ITERATOR_PAUSE;
    }
    //printf("start: %zu, stop: %zu, step: %lld, loc: %zu, stop: %d\n", islice_out->sl.start, islice_out->sl.stop, islice_out->sl.step, islice_out->loc, islice_out->stop_);
    return ITERATOR_GO;
}
int SliceIterator_stop(void * islice) {
    if (!islice) {
        return ITERATOR_STOP;
    }
    return ((SliceIterator *)islice)->stop_;
}
int SliceIterator_next(void * islice_, void * el) {
    SliceIterator * islice = (SliceIterator *) islice_;
    if (!islice || islice->stop_ == ITERATOR_STOP) {
        return 1;
    }
    if (islice->sl.step > 0) { // start is inclusive, stop is exclusive, 
        if (islice->stop_ == ITERATOR_PAUSE) {
            islice->stop_ = ITERATOR_GO;
        } else if (islice->sl.stop_ - islice->sl.step <= islice->loc) {
            islice->stop_ = ITERATOR_STOP;
        } else {
            islice->loc += islice->sl.step;
        }
    } else { // start is exclusive, stop is inclusive
        if (islice->stop_ == ITERATOR_PAUSE) {
            islice->stop_ = ITERATOR_GO;
            islice->loc -= 1;
        } else {
            islice->loc += islice->sl.step;
        }
        if (islice->stop_ == ITERATOR_STOP_1) {
            islice->stop_ = ITERATOR_STOP;
        } else {
            if (islice->sl.stop_ < islice->loc) {
                if (islice->sl.stop_ - islice->sl.step >= islice->loc) {
                    islice->stop_ = ITERATOR_STOP_1;
                }
            } else {
                if (-islice->sl.step > islice->loc) {
                    islice->stop_ = ITERATOR_STOP_1;
                }
            }
        }
    }
    *((size_t *) el) = islice->loc;
    return 0;
}