/*****************************************************************************
 * Test cases for libxlsxwriter.
 *
 * Test to compare output against Excel files.
 *
 * Copyright 2014-2020, John McNamara, jmcnamara@cpan.org
 *
 */

#include "xlsxwriter.h"

int main() {

    lxw_workbook  *workbook  = workbook_new("test_rich_string55.xlsx");
    lxw_worksheet *worksheet = workbook_add_worksheet(workbook, NULL);

    char *rich_string = "<r><t xml:space=\"preserve\">This is </t></r><r><rPr><b/><sz val=\"11\"/><color theme=\"1\"/><rFont val=\"Calibri\"/><family val=\"2\"/><scheme val=\"minor\"/></rPr><t>bold</t></r><r><rPr><sz val=\"11\"/><color theme=\"1\"/><rFont val=\"Calibri\"/><family val=\"2\"/><scheme val=\"minor\"/></rPr><t xml:space=\"preserve\"> and this is </t></r><r><rPr><i/><sz val=\"11\"/><color theme=\"1\"/><rFont val=\"Calibri\"/><family val=\"2\"/><scheme val=\"minor\"/></rPr><t>italic</t></r>";

    lxw_format *bold = workbook_add_format(workbook);
    lxw_format *italic = workbook_add_format(workbook);

    format_set_bold(bold);
    format_set_italic(italic);

    worksheet_set_column(worksheet, 0, 0, 30, NULL);

    worksheet_write_string(worksheet, CELL("A1"), "Foo", bold);
    worksheet_write_string(worksheet, CELL("A2"), "Bar", italic);

    worksheet_write_rich_string_html(worksheet, CELL("A3"), rich_string, NULL);

    return workbook_close(workbook);
}
