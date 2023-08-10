#include <stdio.h>
#include "find_key.h"
#include "rot13.h"

int main() {
    char *message = "sbe bhe grnz oneorphr!\n"
                    "Jura qbrf vg fgneg naq funyy V oevat fbzrguvat?\n"
                    "Qba'g sbetrg gur oernq sbe gur cnegl.";

    /* Figure out the key by brute-force approach */
    find_key(message);
    char *result = decode_rot13(message);
    printf("\n%s", result);
    return 0;
}
