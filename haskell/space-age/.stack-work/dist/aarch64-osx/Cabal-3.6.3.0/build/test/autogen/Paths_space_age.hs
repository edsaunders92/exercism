{-# LANGUAGE CPP #-}
{-# LANGUAGE NoRebindableSyntax #-}
{-# OPTIONS_GHC -fno-warn-missing-import-lists #-}
{-# OPTIONS_GHC -w #-}
module Paths_space_age (
    version,
    getBinDir, getLibDir, getDynLibDir, getDataDir, getLibexecDir,
    getDataFileName, getSysconfDir
  ) where


import qualified Control.Exception as Exception
import qualified Data.List as List
import Data.Version (Version(..))
import System.Environment (getEnv)
import Prelude


#if defined(VERSION_base)

#if MIN_VERSION_base(4,0,0)
catchIO :: IO a -> (Exception.IOException -> IO a) -> IO a
#else
catchIO :: IO a -> (Exception.Exception -> IO a) -> IO a
#endif

#else
catchIO :: IO a -> (Exception.IOException -> IO a) -> IO a
#endif
catchIO = Exception.catch

version :: Version
version = Version [1,2,0,6] []

getDataFileName :: FilePath -> IO FilePath
getDataFileName name = do
  dir <- getDataDir
  return (dir `joinFileName` name)

getBinDir, getLibDir, getDynLibDir, getDataDir, getLibexecDir, getSysconfDir :: IO FilePath



bindir, libdir, dynlibdir, datadir, libexecdir, sysconfdir :: FilePath
bindir     = "/Users/edsaunders/Personal/exercism/haskell/space-age/.stack-work/install/aarch64-osx/0356dbbdeef71c8a256890c2d6ad4833c22f5fa157274b9ff22eb809cbc4a964/9.2.7/bin"
libdir     = "/Users/edsaunders/Personal/exercism/haskell/space-age/.stack-work/install/aarch64-osx/0356dbbdeef71c8a256890c2d6ad4833c22f5fa157274b9ff22eb809cbc4a964/9.2.7/lib/aarch64-osx-ghc-9.2.7/space-age-1.2.0.6-7vCHQ7eLpoN6D4LdrWLSYE-test"
dynlibdir  = "/Users/edsaunders/Personal/exercism/haskell/space-age/.stack-work/install/aarch64-osx/0356dbbdeef71c8a256890c2d6ad4833c22f5fa157274b9ff22eb809cbc4a964/9.2.7/lib/aarch64-osx-ghc-9.2.7"
datadir    = "/Users/edsaunders/Personal/exercism/haskell/space-age/.stack-work/install/aarch64-osx/0356dbbdeef71c8a256890c2d6ad4833c22f5fa157274b9ff22eb809cbc4a964/9.2.7/share/aarch64-osx-ghc-9.2.7/space-age-1.2.0.6"
libexecdir = "/Users/edsaunders/Personal/exercism/haskell/space-age/.stack-work/install/aarch64-osx/0356dbbdeef71c8a256890c2d6ad4833c22f5fa157274b9ff22eb809cbc4a964/9.2.7/libexec/aarch64-osx-ghc-9.2.7/space-age-1.2.0.6"
sysconfdir = "/Users/edsaunders/Personal/exercism/haskell/space-age/.stack-work/install/aarch64-osx/0356dbbdeef71c8a256890c2d6ad4833c22f5fa157274b9ff22eb809cbc4a964/9.2.7/etc"

getBinDir     = catchIO (getEnv "space_age_bindir")     (\_ -> return bindir)
getLibDir     = catchIO (getEnv "space_age_libdir")     (\_ -> return libdir)
getDynLibDir  = catchIO (getEnv "space_age_dynlibdir")  (\_ -> return dynlibdir)
getDataDir    = catchIO (getEnv "space_age_datadir")    (\_ -> return datadir)
getLibexecDir = catchIO (getEnv "space_age_libexecdir") (\_ -> return libexecdir)
getSysconfDir = catchIO (getEnv "space_age_sysconfdir") (\_ -> return sysconfdir)




joinFileName :: String -> String -> FilePath
joinFileName ""  fname = fname
joinFileName "." fname = fname
joinFileName dir ""    = dir
joinFileName dir fname
  | isPathSeparator (List.last dir) = dir ++ fname
  | otherwise                       = dir ++ pathSeparator : fname

pathSeparator :: Char
pathSeparator = '/'

isPathSeparator :: Char -> Bool
isPathSeparator c = c == '/'