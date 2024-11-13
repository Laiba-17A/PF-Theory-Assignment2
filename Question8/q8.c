#include <stdio.h>

int BinaryToDecimal(int binary) {
    int decimal = 0;
    int base = 1;
    
    while(binary > 0) {
        int lastDigit = binary % 10;
        binary = binary / 10;
        decimal += lastDigit * base;
        base = base * 2;
    }
    return decimal;
}

int DecimalToBinary(int decimal) {
    int binary = 0;
    int place = 1;
    
    while(decimal > 0) {
        binary = binary + (decimal % 2) * place;
        decimal = decimal / 2;
        place = place * 10;
    }
    return binary;
}

int isValidBinary(int num) {
    while(num > 0) {
        if(num % 10 > 1) return 0;
        num = num / 10;
    }
    return 1;
}

int hexDigitToDecimal(char c) {
    if(c >= '0' && c <= '9') return c - '0';
    if(c >= 'A' && c <= 'F') return c - 'A' + 10;
    if(c >= 'a' && c <= 'f') return c - 'a' + 10;
    return -1;
}

char decimalToHexDigit(int n) {
    if(n < 10) return n + '0';
    return (n - 10) + 'A';
}

void DecimalToHexadecimal(int decimal) {
    int binary = DecimalToBinary(decimal);
    
    char hex[100];
    int i = 0;
    
    if(decimal == 0) {
        printf("Hexadecimal: 0\n");
        return;
    }
    
    while(decimal > 0) {
        int remainder = decimal % 16;
        hex[i] = decimalToHexDigit(remainder);
        decimal = decimal / 16;
        i++;
    }
    
    printf("Hexadecimal: ");
    while(i > 0) {
        i--;
        printf("%c", hex[i]);
    }
    printf("\n");
}

void HexadecimalToDecimal(char hex[]) {
    int decimal = 0;
    int base = 1;
    
    int len = 0;
    while(hex[len] != '\0') len++;
    
    for(int i = len - 1; i >= 0; i--) {
        int value = hexDigitToDecimal(hex[i]);
        if(value == -1) {
            printf("Invalid hexadecimal number!\n");
            return;
        }
        decimal += value * base;
        base *= 16;
    }
    
    printf("Decimal: %d\n", decimal);
}

void BinaryToHexadecimal(int binary) {
    if(!isValidBinary(binary)) {
        printf("Invalid binary number!\n");
        return;
    }
    
    int decimal = BinaryToDecimal(binary);
    
    DecimalToHexadecimal(decimal);
}

void HexadecimalToBinary(char hex[]) {
    int decimal = 0;
    int base = 1;
    int len = 0;
    while(hex[len] != '\0') len++;
    
    for(int i = len - 1; i >= 0; i--) {
        int value = hexDigitToDecimal(hex[i]);
        if(value == -1) {
            printf("Invalid hexadecimal number!\n");
            return;
        }
        decimal += value * base;
        base *= 16;
    }
    
    printf("Binary: %d\n", DecimalToBinary(decimal));
}

int main() {
    int choice, number;
    char hex[100];
    
    while(1) {
        printf("\nNumber System Converter\n");
        printf("1. Binary to Decimal\n");
        printf("2. Decimal to Binary\n");
        printf("3. Decimal to Hexadecimal\n");
        printf("4. Hexadecimal to Decimal\n");
        printf("5. Binary to Hexadecimal\n");
        printf("6. Hexadecimal to Binary\n");
        printf("7. Exit\n");
        printf("Enter your choice (1-7): ");
        
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Enter binary number: ");
                scanf("%d", &number);
                if(!isValidBinary(number)) {
                    printf("Invalid binary number!\n");
                    break;
                }
                printf("Decimal: %d\n", BinaryToDecimal(number));
                break;
                
            case 2:
                printf("Enter decimal number: ");
                scanf("%d", &number);
                printf("Binary: %d\n", DecimalToBinary(number));
                break;
                
            case 3:
                printf("Enter decimal number: ");
                scanf("%d", &number);
                DecimalToHexadecimal(number);
                break;
                
            case 4:
                printf("Enter hexadecimal number: ");
                scanf("%s", hex);
                HexadecimalToDecimal(hex);
                break;
                
            case 5:
                printf("Enter binary number: ");
                scanf("%d", &number);
                BinaryToHexadecimal(number);
                break;
                
            case 6:
                printf("Enter hexadecimal number: ");
                scanf("%s", hex);
                HexadecimalToBinary(hex);
                break;
                
            case 7:
                printf("Goodbye!\n");
                return 0;
                
            default:
                printf("Invalid choice! Please enter 1-7\n");
        }
    }
    
    return 0;
}