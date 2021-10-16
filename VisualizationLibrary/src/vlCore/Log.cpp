/**************************************************************************************/
/*                                                                                    */
/*  Visualization Library                                                             */
/*  http://visualizationlibrary.org                                                   */
/*                                                                                    */
/*  Copyright (c) 2005-2020, Michele Bosi                                             */
/*  All rights reserved.                                                              */
/*                                                                                    */
/*  Redistribution and use in source and binary forms, with or without modification,  */
/*  are permitted provided that the following conditions are met:                     */
/*                                                                                    */
/*  - Redistributions of source code must retain the above copyright notice, this     */
/*  list of conditions and the following disclaimer.                                  */
/*                                                                                    */
/*  - Redistributions in binary form must reproduce the above copyright notice, this  */
/*  list of conditions and the following disclaimer in the documentation and/or       */
/*  other materials provided with the distribution.                                   */
/*                                                                                    */
/*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND   */
/*  ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED     */
/*  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE            */
/*  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR  */
/*  ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES    */
/*  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;      */
/*  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON    */
/*  ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT           */
/*  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS     */
/*  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.                      */
/*                                                                                    */
/**************************************************************************************/

#include <vlCore/Log.hpp>
#include <vlCore/VisualizationLibrary.hpp>
#include <vlCore/GlobalSettings.hpp>
#include <vlCore/Vector3.hpp>
#include <vlCore/Say.hpp>
#include <vlCore/ScopedMutex.hpp>
#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace vl;

namespace
{
#if defined(VL_PLATFORM_WINDOWS)
  struct ScopedColor
  {
    WORD wAttributes;
    ScopedColor(WORD c)
    {
      CONSOLE_SCREEN_BUFFER_INFO screen_info;
      HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
      GetConsoleScreenBufferInfo(
        hConsole,
        &screen_info
      );
      wAttributes = screen_info.wAttributes;
      SetConsoleTextAttribute(hConsole, c);
    }
    ~ScopedColor()
    {
      // restore the color
      HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
      SetConsoleTextAttribute(hConsole, wAttributes );
    }
  };
  #define SET_TEXT_COLOR_YELLOW() ScopedColor scoped_color(FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
  #define SET_TEXT_COLOR_RED()    ScopedColor scoped_color(FOREGROUND_RED|FOREGROUND_INTENSITY);
  #define SET_TEXT_COLOR_PURPLE() ScopedColor scoped_color(FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
  #define SET_TEXT_COLOR_GREEN() ScopedColor scoped_color(FOREGROUND_GREEN|FOREGROUND_INTENSITY);
  #define SET_TEXT_COLOR_BLUE() ScopedColor scoped_color(FOREGROUND_BLUE|FOREGROUND_INTENSITY);
#else
  struct ScopedColor
  {
    ScopedColor(const char* color)
    {
      //30 black foreground
      //31 red foreground
      //32 green foreground
      //33 brown foreground
      //34 blue foreground
      //35 magenta (purple) foreground
      //36 cyan (light blue) foreground
      //37 gray foreground

      //40 black background
      //41 red background
      //42 green background
      //43 brown background
      //44 blue background
      //45 magenta background
      //46 cyan background
      //47 white background

      //0 reset all attributes to their defaults
      //1 set bold
      //5 set blink
      //7 set reverse video
      //22 set normal intensity
      //25 blink off
      //27 reverse video off

      // example:
      // "\033[34mThis is blue.\033[0m"
      // "\033[45;37mGrey on purple.\033[0m"

      printf("%s", color);
    }
    ~ScopedColor()
    {
      // restore normal color
      printf("%s", "\033[0m");
    }
  };
  #define SET_TEXT_COLOR_YELLOW() ScopedColor scoped_color("\033[1;33m");
  #define SET_TEXT_COLOR_RED()    ScopedColor scoped_color("\033[31m");
  #define SET_TEXT_COLOR_PURPLE() ScopedColor scoped_color("\033[1;31m");
  #define SET_TEXT_COLOR_GREEN()  ScopedColor scoped_color("\033[1;32m");
  #define SET_TEXT_COLOR_BLUE()  ScopedColor scoped_color("\033[1;34m");
#endif
}
//-----------------------------------------------------------------------------
// Log
//-----------------------------------------------------------------------------
void Log::notify(const String& log)
{
  //! Synchronize log across threads.
  ScopedMutex mutex(Log::logMutex());

  SET_TEXT_COLOR_GREEN()
  if(defLogger() && globalSettings()->verbosityLevel() != vl::VEL_VERBOSITY_SILENT)
    defLogger()->printImplementation(LL_LogNotify, log);
}
//-----------------------------------------------------------------------------
void Log::print(const String& log)
{
  //! Synchronize log across threads.
  ScopedMutex mutex(Log::logMutex());

  if(defLogger() && globalSettings()->verbosityLevel() != vl::VEL_VERBOSITY_SILENT)
    defLogger()->printImplementation(LL_LogPrint, log);
}
//-----------------------------------------------------------------------------
void Log::debug(const String& log)
{
  //! Synchronize log across threads.
  ScopedMutex mutex(Log::logMutex());

  SET_TEXT_COLOR_BLUE()
  if(defLogger() && globalSettings()->verbosityLevel() >= vl::VEL_VERBOSITY_DEBUG)
    defLogger()->printImplementation(LL_LogDebug, log);
}
//-----------------------------------------------------------------------------
void Log::warning(const String& log)
{
  //! Synchronize log across threads.
  ScopedMutex mutex(Log::logMutex());

  SET_TEXT_COLOR_YELLOW()
  if(defLogger() && globalSettings()->verbosityLevel() >= vl::VEL_VERBOSITY_ERROR)
    defLogger()->printImplementation(LL_LogWarning, log);
}
//-----------------------------------------------------------------------------
void Log::error(const String& log)
{
  //! Synchronize log across threads.
  ScopedMutex mutex(Log::logMutex());

  SET_TEXT_COLOR_RED()
  if(defLogger() && globalSettings()->verbosityLevel() >= vl::VEL_VERBOSITY_ERROR)
    defLogger()->printImplementation(LL_LogError, log);
}
//-----------------------------------------------------------------------------
void Log::bug(const String& log)
{
  //! Synchronize log across threads.
  ScopedMutex mutex(Log::logMutex());

  SET_TEXT_COLOR_PURPLE()
  if(defLogger() && globalSettings()->verbosityLevel() >= vl::VEL_VERBOSITY_ERROR)
    defLogger()->printImplementation(LL_LogBug, log);
}
//------------------------------------------------------------------------------
void vl::log_failed_check(const char* expr, const char* file, int line)
{
  VL_LOG_ERROR << "Condition '" << expr << "' failed at " << file << ":" << line << "\n";
  fflush(stdout);
  fflush(stderr);

  #if defined(VL_PLATFORM_WINDOWS) && VL_MESSAGEBOX_CHECK == 1
     String msg = Say("Condition \"%s\" failed.\n\n%s:%n\n") << expr << file << line;
     MessageBox(NULL, (wchar_t*)msg.ptr(), L"Visualization Library Debug", MB_OK | MB_ICONEXCLAMATION);
  #endif
}
//-----------------------------------------------------------------------------
// Log mutex.
//-----------------------------------------------------------------------------
IMutex* Log::mLogMutex = NULL;
//-----------------------------------------------------------------------------
// StandardLog
//-----------------------------------------------------------------------------
void StandardLog::setLogFile(const String& file)
{
  mLogFile = file;

  if (mFile.is_open())
    mFile.close();

  if (!file.empty())
    mFile.open(file.toStdString().c_str());
}
//-----------------------------------------------------------------------------
void StandardLog::printImplementation(ELogLevel, const String& log)
{
  if (log.empty())
    return;

  std::string stdstr = log.toStdString();
  std::cout << stdstr << std::flush;

  if (mFile.is_open())
    mFile << stdstr << std::flush;
}
//-----------------------------------------------------------------------------
