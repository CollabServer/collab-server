#pragma once

#include "CvRDT/PNCounter.h"

namespace CRDT {
namespace CvRDT {


void PNCounter_example() {
    std::cout << "\n----- CvRDT PNCounter Example ----------\n";

    PNCounter<int, std::string> data0("user1");
    PNCounter<int, std::string> data1("user2");


    // --- Replicate 0 (data0) ---
    data0.increment();
    data0.increment();
    data0.increment();
    data0.decrement();
    // = 2


    // --- Replicate 1 (data1) ---
    data1.increment();
    data1.increment();
    data1.decrement();
    data1.decrement();
    data1.decrement();
    // = -1


    // --- Final ---
    std::cout << "data0 before merge: " << data0 << "\n";
    std::cout << "data1 before merge: " << data1 << "\n";

    // Merge result -> 1
    data0.merge(data1);
    data1.merge(data0);

    std::cout << "data0 after merge: " << data0 << "\n";
    std::cout << "data1 after merge: " << data1 << "\n";
}


}} // End namespaces