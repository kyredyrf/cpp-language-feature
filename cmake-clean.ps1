param (
    
)
end {
    . (Join-Path "." "cmake-utility.ps1")

    try {
        $outputPaths = Get-ChildItem -Recurse -Filter "cmake-output"
        $outputPaths | ForEach-Object {
            Remove-Item -Recurse -Force -Path $_.FullName -ErrorAction Ignore
        }

        $cmakeListPaths = Get-ChildItem -Recurse -Filter "CMakeLists.txt"
        $cmakeListPaths | ForEach-Object {
            Remove-Item -Recurse -Force -Path $_.FullName -ErrorAction Ignore
        }

        if ((Get-OS) -eq "macOS") {
            dot_clean "."
        }
    }
    catch {
        "$($_.Exception.Message)`n$($_.ScriptStackTrace)" | Write-Host -ForegroundColor Magenta
    }
    finally {
    }
}
