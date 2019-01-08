#ifndef CUBEMODEL_H
#define CUBEMODEL_H

#include "Model.h"

class CubeModel : public ModelWithScreenLocation<BoxedScreenLocation>
{
    public:
    
        static void InitialiseChoices();

        CubeModel(wxXmlNode *node, const ModelManager &manager, bool zeroBased = false);
        virtual ~CubeModel();

        virtual const std::vector<std::string> &GetBufferStyles() const override;
        virtual void GetBufferSize(const std::string &type, const std::string &camera, const std::string &transform, int &BufferWi, int &BufferHi) const override;
        virtual int GetNumPhysicalStrings() const override { return GetStrings(); }
        virtual bool SupportsXlightsModel() override { return true; }
        virtual bool SupportsExportAsCustom() const override { return true; }
        virtual bool SupportsWiringView() const override { return true; }
        virtual void ExportXlightsModel() override;
        virtual void ImportXlightsModel(std::string filename, xLightsFrame* xlights, float& min_x, float& max_x, float& min_y, float& max_y) override;
        virtual void InitRenderBufferNodes(const std::string &type, const std::string &camera, const std::string &transform,
            std::vector<NodeBaseClassPtr> &Nodes, int &BufferWi, int &BufferHi) const override;
        virtual int NodeRenderOrder() override { return 1; }
        virtual int GetStrandLength(int strand) const override { return _strandLength; }
        virtual int GetNumStrands() const override { return _strands; };
        virtual int MapToNodeIndex(int strand, int node) const override;

        virtual void AddTypeProperties(wxPropertyGridInterface *grid) override;
        virtual int OnPropertyGridChange(wxPropertyGridInterface *grid, wxPropertyGridEvent& event) override;

    protected:
        int GetStartIndex() const;
        int GetStyleIndex() const;
        std::tuple<int, int, int>& FlipX(std::tuple<int, int, int>& pt) const;
        std::tuple<int, int, int>& RotateY90Degrees(std::tuple<int, int, int>& pt, int by) const;
        std::tuple<int, int, int>& RotateZ90Degrees(std::tuple<int, int, int>& pt, int by) const;
        std::tuple<int, int, int>& RotateX90Degrees(std::tuple<int, int, int>& pt, int by) const;
        int CalcTransformationIndex() const;
        std::vector<std::tuple<int, int, int>> BuildCube(int w, int h, int d) const;
        bool IsStrandPerLayer() const;
        bool IsStrandPerLine() const;
        int GetStrings() const;

        CubeModel(const ModelManager &manager);
        virtual void InitModel() override;
        
    private:
        unsigned long _lastChangeCount = -999;
        int _strandLength = 1;
        int _strands = 1;
};

#endif // CUBEMODEL_H