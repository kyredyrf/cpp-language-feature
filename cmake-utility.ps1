param (

)
end {
    try {
        function Get-OS {
            param (

            )
            end {
                if ($PSVersionTable.OS.StartsWith("Microsoft Windows")) {
                    "Windows"
                }
                elseif ($PSVersionTable.OS.StartsWith("Darwin")) {
                    "macOS"
                }
                else {
                    throw $PSVersionTable.OS
                }
            }
        }
    }
    catch {
        "$($_.Exception.Message)`n$($_.ScriptStackTrace)" | Write-Host -ForegroundColor Magenta
    }
    finally {

    }
}
