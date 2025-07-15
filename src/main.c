static char const* EMPTY_PDF = (
    // force line break
    "%PDF-1.3\n"
    "1 0 obj\n"
    "<< /Type /Catalog /Pages 2 0 R >>\n"
    "endobj\n"
    "2 0 obj\n"
    "<< /Type /Pages /Kids [] /Count 0 >>\n"
    "endobj\n"
    "xref\n"
    "0 3\n"
    "0000000000 65535 f \n"
    "0000000009 00000 n \n"
    "0000000058 00000 n \n"
    "trailer << /Size 3 /Root 1 0 R >>\n"
    "startxref\n"
    "110\n"
    "%%EOF\n");


#include <stdio.h>

int main() {
    FILE *fp = fopen("example.pdf", "wb");
    if (!fp) {
        perror("Failed to open file");
        return 1;
    }

    // PDF Header
    fprintf(fp, "%%PDF-1.4\n");

    // Object 1: Catalog
    fprintf(fp, "1 0 obj\n");
    fprintf(fp, "<< /Type /Catalog /Pages 2 0 R >>\n");
    fprintf(fp, "endobj\n");

    // Object 2: Pages
    fprintf(fp, "2 0 obj\n");
    fprintf(fp, "<< /Type /Pages /MediaBox [0 0 300 400] /Count 1 /Kids [3 0 R] >>\n");
    fprintf(fp, "endobj\n");

    // Object 3: Page
    fprintf(fp, "3 0 obj\n");
    fprintf(fp, "<< /Type /Page /Parent 2 0 R /Contents 4 0 R >>\n");
    fprintf(fp, "endobj\n");

    // Object 4: Content Stream
    fprintf(fp, "4 0 obj\n");
    fprintf(fp, "<< /Length 44 >>\n");
    fprintf(fp, "stream\n");
    fprintf(fp, "BT\n");
    fprintf(fp, "/F1 24 Tf\n");
    fprintf(fp, "100 300 Td\n");
    fprintf(fp, "(Hello, PDF World!) Tj\n");
    fprintf(fp, "ET\n");
    fprintf(fp, "endstream\n");
    fprintf(fp, "endobj\n");

    // Object 5: Font
    fprintf(fp, "5 0 obj\n");
    fprintf(fp, "<< /Type /Font /Subtype /Type1 /BaseFont /Helvetica >>\n");
    fprintf(fp, "endobj\n");

    // Cross-reference table
    fprintf(fp, "xref\n");
    fprintf(fp, "0 6\n");
    fprintf(fp, "0000000000 65535 f \n");
    fprintf(fp, "0000000010 00000 n \n");
    fprintf(fp, "0000000060 00000 n \n");
    fprintf(fp, "0000000110 00000 n \n");
    fprintf(fp, "0000000200 00000 n \n");
    fprintf(fp, "0000000270 00000 n \n");

    // Trailer
    fprintf(fp, "trailer\n");
    fprintf(fp, "<< /Size 6 /Root 1 0 R >>\n");
    fprintf(fp, "startxref\n");
    fprintf(fp, "300\n");
    fprintf(fp, "%%EOF\n");

    fclose(fp);
    return 0;
}
