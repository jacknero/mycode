import Directory

main = ( getDirectoryContents "." ) >>= printList

printList :: [String] -> IO()
printList ls = pList $ filter notCDPD ls
  where
    pList :: [String] -> IO ()
    pList (x:xs) = do c <- getCurrentDirectory
                      putStrLn ( c ++ x )
                      pList xs
    pList [] = putStr ""

notCDPD :: String -> Bool
notCDPD "."   = False
notCDPD ".."  = False
notCDPD other = True
