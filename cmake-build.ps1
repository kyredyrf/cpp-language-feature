param (
    [string] $BuildPath
)
end {
    . (Join-Path "." "cmake-utility.ps1")

    try {
        $prebuildPath = Join-Path $PSScriptRoot "cmake-prebuild-unversioned.ps1"
        if (Test-Path $prebuildPath) {
            & $prebuildPath
        }

        $cmakeListPath = Join-Path $BuildPath "src" "CMakeLists.txt"
        if (-not (Test-Path $cmakeListPath)) {
            Copy-Item -Path (Join-Path "." "CMakeLists-default.txt") -Destination $cmakeListPath
        }

        Push-Location $BuildPath
        cmake --version

        $outputPath = Join-Path "." "cmake-output"
        if (Test-Path $outputPath) {
            Remove-Item -Recurse -Force -Path $outputPath -ErrorAction Ignore
        }
        [void](New-Item -ItemType Directory $outputPath)

        $logPath = Join-Path $outputPath "build.log"
        "" | Write-Host > $logPath
        cmake -B $outputPath -S (Join-Path "." "src") >> $logPath
        cmake --build $outputPath -- -r >> $logPath

        $appPath = & {
            switch (Get-OS) {
                "Windows" {
                    Join-Path $outputPath "Debug" "cpp_app.exe"
                }
                "macOS" {
                    Join-Path $outputPath "cpp_app"
                }
            }
        }
        & $appPath
    }
    catch {
        "$($_.Exception.Message)`n$($_.ScriptStackTrace)" | Write-Host -ForegroundColor Magenta
    }
    finally {
        Pop-Location
    }
}
