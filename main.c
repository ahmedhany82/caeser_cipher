#include "find_key.h"

int main() {
    char *message = "sbe bhe grnz oneorphr!\n"
                    "Jura qbrf vg fgneg naq funyy V oevat fbzrguvat?\n"
                    "Qba'g sbetrg gur oernq sbe gur cnegl.";

    /* Figure out the key by brute-force approach */
    find_key(message);
    return 0;
}
