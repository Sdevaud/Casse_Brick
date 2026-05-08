#pragma once

#include <unordered_map>

namespace file {
  enum class Keyword {
    OUTPUT,
    SCORE,
    LIFES,
    PADDLE,
    BRICKS,
    BALLS,
    UNKNOWN
  };

  inline std::unordered_map<std::string, Keyword> keywordMap = {
    {"output:", Keyword::OUTPUT},
    {"score", Keyword::SCORE},
    {"lives", Keyword::LIFES},
    {"paddle", Keyword::PADDLE},
    {"bricks", Keyword::BRICKS},
    {"balls", Keyword::BALLS},
    {"unknow", Keyword::UNKNOWN}
  };
}

namespace graphical {
  enum class Color {
    RED,
    ORANGE,
    YELLOW,
    GREEN,
    INDIGO,
    BLUE,
    VIOLET
  };

  enum class ButtonId {
    Exit,
    Open,
    Save,
    Restart,
    Start,
    Step,
    Stop
  };

  enum class InfoId {
    Infos,
    Score,
    Lives,
    Bricks,
    Balls
  };
  
}

