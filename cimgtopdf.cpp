#include "cimgtopdf.h"

CImgToPdf::CImgToPdf(QGraphicsScene* scene)
{
        QPrinter printer(QPrinter::HighResolution);
        printer.setPageSize(QPrinter::A4);
        printer.setOrientation(QPrinter::Portrait);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setOutputFileName("test.pdf"); // file will be created in your build directory (where debug/release directories are)

        QPainter p;

        if(!p.begin(&printer))
        {
            return;
        }
        scene->render(&p);
        p.end();
}

