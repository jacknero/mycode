module Main where
import System

main = do
        args <- getArgs
        putStrLn (join args " ")
        where
              join :: [String] -> String -> String
              join [] sep = ""
              join [x] sep = x
              join (x:xs) sep = x ++ sep ++ (join xs sep)

