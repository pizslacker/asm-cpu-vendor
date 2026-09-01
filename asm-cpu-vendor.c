#include <stdio.h>
#include <string.h>

void get_cpu_vendor(char *vendor) {
    unsigned int eax, ebx, ecx, edx;

    // GCC Extended Inline Assembly
    __asm__ volatile (
        "cpuid"
        : "=a" (eax), "=b" (ebx), "=c" (ecx), "=d" (edx) // Output operands
        : "a" (0)                                        // Input operands
    );

    // The vendor string is 12 characters, stored across EBX, EDX, and ECX (in that order).
    // We copy the 4 bytes from each register directly into our character array.
    memcpy(vendor, &ebx, 4);
    memcpy(vendor + 4, &edx, 4);
    memcpy(vendor + 8, &ecx, 4);
    vendor[12] = '\0'; // Null-terminate the string
}

int main() {
    char vendor_string[13];
    get_cpu_vendor(vendor_string);
    
    printf("CPU Vendor: %s\n", vendor_string);
    
    return 0;
}