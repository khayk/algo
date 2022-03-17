file(GLOB no_group_source_files
    "*.cpp"
    "*.h"
)
source_group("" FILES ${no_group_source_files})

file(GLOB array
    "array/*.h"
    "array/*.cpp"
)
source_group("array" FILES ${array})

file(GLOB geometry
    "geometry/*.h"
    "geometry/*.cpp"
)
source_group("geometry" FILES ${geometry})

file(GLOB graph
    "graph/*.h"
    "graph/*.cpp"
)
source_group("graph" FILES ${graph})

file(GLOB randomized
    "randomized/*.h"
    "randomized/*.cpp"
)
source_group("randomized" FILES ${randomized})

file(GLOB search
    "search/*.h"
    "search/*.cpp"
)
source_group("search" FILES ${search})

file(GLOB sort
    "sort/*.h"
    "sort/*.cpp"
)
source_group("sort" FILES ${sort})

file(GLOB stack
    "stack/*.h"
    "stack/*.cpp"
)
source_group("stack" FILES ${stack})