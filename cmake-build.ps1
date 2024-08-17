param (
    [string] $BuildPath
)
end {
    . ([System.IO.Path]::Combine('.', 'cmake-utility.ps1'))

    try {
        $prebuildPath = [System.IO.Path]::Combine($PSScriptRoot, 'cmake-prebuild-unversioned.ps1')
        if (Test-Path $prebuildPath) {
            & $prebuildPath
        }

        $cmakeListPath = [System.IO.Path]::Combine($BuildPath, 'src', 'CMakeLists.txt')
        if (-not (Test-Path $cmakeListPath)) {
            Copy-Item -Path ([System.IO.Path]::Combine('.', 'CMakeLists-default.txt')) -Destination $cmakeListPath
        }

        Push-Location $BuildPath
        & cmake --version

        $buildLogPath = [System.IO.Path]::Combine('.', 'cmake-build-unversioned.log')
        $execLogPath = [System.IO.Path]::Combine('.', 'cmake-exec-unversioned.log')
        (Get-Date) > $buildLogPath
        (Get-Date) > $execLogPath
        @('msvc', 'gcc', 'clang') | ForEach-Object {
            $name = $_
            $outputPath = [System.IO.Path]::Combine('.', 'cmake-output-unversioned', $name)
            if (Test-Path $outputPath) {
                Remove-Item -Path $outputPath -Recurse -Force -ErrorAction Ignore
            }
            [void](New-Item -Path $outputPath -ItemType Directory)

            "### build $name ###" >> $buildLogPath
            $sourcePath = [System.IO.Path]::Combine('.', 'src')
            switch ($name) {
                'msvc' {
                    & cmake -B $outputPath -S $sourcePath -G 'Visual Studio 17 2022' >> $buildLogPath 2>&1
                }
                'gcc' {
                    & cmake -B $outputPath -S $sourcePath -G 'MinGW Makefiles' >> $buildLogPath 2>&1
                }
                'clang' {
                    & cmake -B $outputPath -S $sourcePath -G 'MinGW Makefiles' -DCMAKE_CXX_COMPILER=clang++ >> $buildLogPath 2>&1
                    # & cmake -B $outputPath -S $sourcePath -G 'Visual Studio 17 2022' -T ClangCL >> $buildLogPath 2>&1
                }
            }
            & cmake --build $outputPath -- -r >> $buildLogPath 2>&1
            (Get-Date) >> $buildLogPath
            '' >> $buildLogPath

            "### exec $name ###" >> $execLogPath
            $appPath = & {
                switch (Get-OS) {
                    'Windows' {
                        $path = [System.IO.Path]::Combine($outputPath, 'Debug', 'cpp_app.exe')
                        if (Test-Path $path) {
                            return $path
                        }
                        $path = [System.IO.Path]::Combine($outputPath, 'cpp_app.exe')
                        if (Test-Path $path) {
                            return $path
                        }
                        throw $path
                    }
                    'macOS' {
                        [System.IO.Path]::Combine($outputPath, 'cpp_app')
                    }
                }
            }
            & $appPath >> $execLogPath 2>&1
            (Get-Date) >> $execLogPath
            '' >> $execLogPath
        }
    }
    catch {
        "$($_.Exception.Message)`n$($_.ScriptStackTrace)" | Write-Host -ForegroundColor Magenta
    }
    finally {
        Pop-Location
    }
}
