
function InitSymbols()
{
    var strProjectName = wizard.FindSymbol('PROJECT_NAME');

    var strOutputRootPath = wizard.FindSymbol('PROJECT_PATH');
    
    var strTargetPath = AppendBackslash(strOutputRootPath) + strProjectName;
    
    strTargetPath = AppendBackslash(strOutputRootPath) + strProjectName;

    wizard.AddSymbol('PROJECT_PATH', AppendBackslash(strTargetPath));
    wizard.AddSymbol('PLUGIN_GUID', wizard.CreateGuid());
    wizard.AddSymbol('SOLUTION_GUID', wizard.CreateGuid());
    return AppendBackslash(strOutputRootPath);
}

function CheckExistingFile(strPath, fileEnd)
{
    var fso = new ActiveXObject("Scripting.FileSystemObject");
    var o = new ActiveXObject( 'WScript.Shell' );
    var strProjectName = wizard.FindSymbol('PROJECT_NAME');
    var filename = strPath + strProjectName + fileEnd;

    if (fso.FileExists(filename))
    {
        do
        {
            p = o.Popup(strProjectName + fileEnd + ' already exist. Delete or rename the existing file and press Retry putton to continue, or press Cancle to exit the wizard',0,'File already exist',53);
        }
        while((p == 4) && fso.FileExists(filename));
        
        if (p == 2)
        {
            throw false;
        }
    }
}

function OnFinish(selProj, selObj) 
{
    try
    {
        InitSymbols();

        var strProjectName = wizard.FindSymbol('PROJECT_NAME');
        var strProjectPath = wizard.FindSymbol('PROJECT_PATH');
        var oSolution = dte.Solution;

        selProj = CreateCustomProject(strProjectName, strProjectPath);

        var infFile = CreateCustomInfFile();
        AddFilesToCustomProj(selProj, strProjectName, strProjectPath, infFile);
        infFile.Delete();

        var strSolutionPath = AppendBackslash(strProjectPath) + strProjectName + ".sln";
        oSolution.SaveAs(strSolutionPath);
    }
    catch(e)
    {
        if ((e != null) && (e.description != null) && (e.description.length != 0))
        {
            SetErrorInfo(e);
            return e.number
        }
    }
}

function CreateCustomProject(strProjectName, strProjectPath)
{
    try
    {
        var strProjTemplatePath = wizard.FindSymbol('TEMPLATES_PATH');
        var strProjTemplate = AppendBackslash(strProjTemplatePath) + 'NETDCPlugin.csproj';

        var Solution = dte.Solution;
        var strSolutionName = "";
        if (wizard.FindSymbol("CLOSE_SOLUTION"))
        {
            Solution.Close();
            strSolutionName = wizard.FindSymbol("VS_SOLUTION_NAME");
            if (strSolutionName.length)
            {
                var strSolutionPath = strProjectPath.substr(0, strProjectPath.length - strProjectName.length);
                Solution.Create(strSolutionPath, strSolutionName);
            }
        }

        var strProjectNameWithExt = '';
        var strProjectDestination = '';
        strProjectNameWithExt = strProjectName + ".csproj";
        strProjectDestination = AppendBackslash(strProjectPath) + strProjectNameWithExt;

        // Process project file...
        wizard.RenderTemplate(strProjTemplate, strProjectNameWithExt, false);

        var oTarget = wizard.FindSymbol("TARGET");
        var prj;
        if (wizard.FindSymbol("WIZARD_TYPE") == vsWizardAddSubProject)  // vsWizardAddSubProject
        {
            var prjItem = oTarget.AddFromFile(strProjectDestination);
            prj = prjItem.SubProject;
        }
        else
        {
            prj = oTarget.AddFromFile(strProjectDestination, true);
        }
        
        return prj;
    }
    catch(e)
    {
        throw e;
    }
}

function DelFile(fso, strWizTempFile)
{
    try
    {
        if (fso.FileExists(strWizTempFile))
        {
            var tmpFile = fso.GetFile(strWizTempFile);
            tmpFile.Delete();
        }
    }
    catch(e)
    {
        throw e;
    }
}

function CreateCustomInfFile()
{
    try
    {
        var fso, TemplatesFolder, TemplateFiles, strTemplate;
        fso = new ActiveXObject('Scripting.FileSystemObject');

        var TemporaryFolder = 2;
        var tfolder = fso.GetSpecialFolder(TemporaryFolder);
        var strTempFolder = AppendBackslash(tfolder.Drive) + tfolder.Name;

        var strWizTempFile = AppendBackslash(strTempFolder) + fso.GetTempName();

        var strTemplatePath = wizard.FindSymbol('TEMPLATES_PATH');
        var strInfFile = AppendBackslash(strTemplatePath) + 'Templates.inf';
        wizard.RenderTemplate(strInfFile, strWizTempFile);

        var WizTempFile = fso.GetFile(strWizTempFile);
        return WizTempFile;
    }
    catch(e)
    {
        throw e;
    }
}

function GetTargetName(strName, strProjectPath, strProjectName)
{
    try
    {
        var strTarget = strName;

        // Replace "[Project]" with project name
        strTarget = strTarget.replace( "[Project]", strProjectName );

        // Replace "[ProjectPath]" with path to project root directory
        strTarget = strTarget.replace("[ProjectPath]", strProjectPath);
        
        return strTarget; 
    }
    catch(e)
    {
        throw e;
    }
}

function AddFilesToCustomProj(proj, strProjectName, strProjectPath, InfFile)
{
    try
    {
        var projItems = proj.ProjectItems

        var strTemplatePath = wizard.FindSymbol('TEMPLATES_PATH');

        var strTpl = '';
        var strName = '';
    
        var strTextStream = InfFile.OpenAsTextStream(1, -2);
        while (!strTextStream.AtEndOfStream)
        {
            strTpl = strTextStream.ReadLine();
            if (strTpl != '')
            {
                strName = strTpl;
                var strFile = GetTargetName(strName, strProjectPath, strProjectName);
                var strTemplate = AppendBackslash(strTemplatePath) + strTpl;
                var bCopyOnly = false;  //"true" will only copy the file from strTemplate to strTarget without rendering/adding to the project
                var strExt = strName.substr(strName.lastIndexOf("."));
                if(strExt==".bmp" || strExt==".ico" || strExt==".gif" || strExt==".rtf" || strExt==".css")
                    bCopyOnly = true;
                wizard.RenderTemplate(strTemplate, strFile, bCopyOnly);
                
                proj.ProjectItems.AddFromFile(strFile);
            }
        }
        strTextStream.Close();
    }
    catch(e)
    {
        throw e;
    }
}

function DisplayMessage(msg, title)
{
    var o = new ActiveXObject('WScript.Shell');

    if (o != null)
    {
        if ((title == null) || (title == ''))
        {
            title = 'Error';
        }
        o.Popup(msg, 0, title, 53);
    }
}

function AppendBackslash(path)
{
    var lastChar = '';
    if (path.length > 0)
    {
        lastChar = path.substr(path.length - 1, 1);
    }
    if (lastChar != '\\')
    {
        path += '\\';
    }
    return path;
}