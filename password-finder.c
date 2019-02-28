/**
 *
 * Solves the password problem for SCP-2212 by taking advantage of the
 * verification hash found in the webpage source code
 *
 * Author: Marion Anderson
 *
 */
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    if (argc != 2) {
        printf("input a known hash\n");
        return -1;
    }
    int32_t deshash = atoi(argv[1]);   // desired hash
    printf("deshash: %d\n", deshash);  // for comparison with found hash

    // passwords are all lower-case latin alphabet characters, so this is doable.
    uint16_t upperchar = 123; // 'z'+1
    uint16_t lowerchar = 97;  // 'a'
    char passtest[7];  // password guessing variable
    int32_t hash = 0;  // 32-bit to match the webpage hashing
    
    // brute-forcing
    int i = 0;  // for hashing
    uint8_t k1, k2, k3, k4, k5, k6, k7;  // testing variables
    for (k1 = lowerchar; k1 < upperchar; k1++) {
        for (k2 = lowerchar; k2 < upperchar; k2++) {
            for (k3 = lowerchar; k3 < upperchar; k3++) {
                for (k4 = lowerchar; k4 < upperchar; k4++) {
                    for (k5 = lowerchar; k5 < upperchar; k5++) {
                        for (k6 = lowerchar; k6 < upperchar; k6++) {
                            for (k7 = lowerchar; k7 < upperchar; k7++) {
                            
        passtest[0] = k1;
        passtest[1] = k2;
        passtest[2] = k3;
        passtest[3] = k4;
        passtest[4] = k5;
        passtest[5] = k6;
        passtest[6] = k7;

        // hash the password and see if it matches
        hash = 0;  // reset hash
        for (i = 0; i < strlen(passtest); i++) {
            hash = ((hash<<5) - hash) + passtest[i];
            hash = hash & hash;
        }
        if (hash == deshash) {
            printf("matching hash: %d\n", hash);
            printf("detected password: %s\n", passtest);
            return 0;
        }
    }}}}}}}

    printf("could not find passcode\n");
    return -1;
}
