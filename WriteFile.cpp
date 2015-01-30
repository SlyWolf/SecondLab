#include "WriteFile.h"
#include <sstream>

WriteFile::WriteFile(const char* file_name)
{
   this->output_file.open(file_name);
   this->closed = false;
}

WriteFile::~WriteFile()
{
   close();
   delete[] this;
}

void WriteFile::close()
{
   if (!this->closed)
   {
      this->output_file.close();
      this->closed = true;
   }
}

void WriteFile::writeLine(String* line)
{
   if (!this->closed && line->length() > 0)
   {
      this->output_file << line->getText() << endl;
   }
}
