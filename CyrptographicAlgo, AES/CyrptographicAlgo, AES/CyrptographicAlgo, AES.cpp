#include <openssl/aes.h>
#include <cstring>

int main() {
    AES_KEY key;
    unsigned char iv[AES_BLOCK_SIZE];
    unsigned char plaintext[] = "This is a secret message";
    unsigned char ciphertext[sizeof(plaintext)];
    unsigned char enc_key[] = "secretkey1234567";

    // Set the encryption key and initialization vector
    AES_set_encrypt_key(enc_key, 128, &key);
    memset(iv, 0x00, AES_BLOCK_SIZE);

    // Encrypt the message
    AES_cbc_encrypt(plaintext, ciphertext, sizeof(plaintext), &key, iv, AES_ENCRYPT);

    // Print the encrypted message
    for (int i = 0; i < sizeof(ciphertext); i++) {
        printf("%02x", ciphertext[i]);
    }
    printf("\n");

    return 0;
}
